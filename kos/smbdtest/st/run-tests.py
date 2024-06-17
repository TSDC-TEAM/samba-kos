#!/usr/bin/python3

import sys
import os
import getopt
import subprocess
import collections
from enum import Enum
from colorama import Fore


class Result(Enum):
    UNKNOWN = 0
    PASS = 1
    SKIP = 2
    FAIL = 3


result_codes = {
    "success": Result.PASS,
    "skip": Result.SKIP,
    "failure": Result.FAIL,
    "error": Result.FAIL,
}


def get_result_code(result):
    try:
        return result_codes[result]
    except KeyError:
        return Result.UNKNOWN


def get_result_text(code):
    if code == Result.PASS:
        return Fore.GREEN + "PASS" + Fore.WHITE
    if code == Result.SKIP:
        return Fore.LIGHTBLACK_EX + "SKIP" + Fore.WHITE
    if code == Result.FAIL:
        return Fore.RED + "FAIL" + Fore.WHITE
    return ""


def get_test_result(output):
    line_num = 0
    for line in output.split("\n"):
        if line.find(":") > 0:
            if line_num == 4:
                return get_result_code(line.split(":")[0])
            line_num += 1
    return ""


def run_command(cmd, args):
    result = subprocess.run([cmd] + args, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)
    return result.returncode, result.stdout.decode("utf-8")


class SmbServer:
    def __init__(self, host="//127.0.0.1", path="tmp"):
        self.host = host
        self.path = path
        self.port = 1490
        self.login = "user"
        self.password = "localntdc2pass"

    def get_connect_params(self):
        return [
            "{}/{}".format(self.host, self.path),
            "-p={}".format(self.port),
            "-U{}%{}".format(self.login, self.password)
        ]


def options_iterator(text):
    for arg in text.split(" "):
        pos = arg.find("=")
        if pos > -1:
            yield arg[:pos], arg[pos + 1:]


class TestOptions:
    def __init__(self, text=""):
        self._server_path = "tmp"
        for key, value in options_iterator(text):
            if key == "server_path":
                self._server_path = value

    @property
    def server_path(self):
        return self._server_path


class Test:
    def __init__(self, name, options="", skip=False):
        self.name = name
        self.skip = skip
        self.options = TestOptions(options)


class SmbTorture:
    def __init__(self):
        self._bin = "smbtorture"
        self._st_path = os.getcwd()

    def _get_default_args(self):
        return ["--configfile={}/client/client.conf".format(self._st_path),
                "--option=\"fss:sequence timeout=1\"",
                "--maximum-runtime=1200",
                "--basedir={}/tmp".format(self._st_path),
                "--format=subunit",
                "--option=torture:progress=no",
                "--option=torture:sharedelay=100000",
                "--option=torture:writetimeupdatedelay=500000",
                "--target=samba3"]

    def run(self, test, server):
        rc, output = run_command(self._bin, self._get_default_args() + server.get_connect_params() + [test.name])
        return get_test_result(output)


class Stat(collections.Counter):
    def __init__(self):
        super().__init__()
        self[Result.PASS] = 0
        self[Result.SKIP] = 0
        self[Result.FAIL] = 0

    def inc(self, result):
        self[result] += 1

    @staticmethod
    def _format_title(text):
        return "{:15s} :".format(text)

    @staticmethod
    def _format_percent(count, total):
        if total > 0:
            percent = count / total * 100
        else:
            percent = 0
        return "{:6.2f}%".format(percent)

    def print(self):
        total_run = self.total() - self[Result.SKIP]
        print("=====================================================================")
        print("{} {:6d}        {:8d}".format(Stat._format_title("Number of tests"), self.total(), total_run))
        print("{} {:6d} {} -------".format(Stat._format_title("Tests skipped"), self[Result.SKIP],
                                           Stat._format_percent(self[Result.SKIP], self.total())))
        print("{} {:6d} {} {}".format(Stat._format_title("Tests failed"), self[Result.FAIL],
                                      Stat._format_percent(self[Result.FAIL], self.total()),
                                      Stat._format_percent(self[Result.FAIL], total_run)))
        print("{} {:6d} {} {}".format(Stat._format_title("Tests passed"), self[Result.PASS],
                                      Stat._format_percent(self[Result.PASS], self.total()),
                                      Stat._format_percent(self[Result.PASS], total_run)))
        print("=====================================================================")


def run_test(test, index, total, server):
    count = sys.stdout.write("TEST {}/{} {}\r".format(index + 1, total, test.name))
    sys.stdout.flush()
    if test.skip:
        res = Result.SKIP
    else:
        res = SmbTorture().run(test, server)
    sys.stdout.write(" " * count + "\r")
    sys.stdout.write("{} {}\n".format(get_result_text(res), test.name))
    return res


def parse_test_from_text(text):
    if text.startswith("-"):
        skip = True
        text = text[1:]
    else:
        skip = False
    pos = text.find(" ")
    if pos > 0:
        name = text[:pos]
        options = text[pos + 1:].strip()
    else:
        name = text
        options = ""
    return Test(name, options, skip)


def load_tests(file):
    res = list()
    with open(file, "r", encoding="utf-8", errors="ignore") as f:
        for line in f.readlines():
            if not line.startswith("#"):
                if line[-1] == "\n":
                    line = line[:-1]
                res.append(parse_test_from_text(line))
    return res


def make_client_config_file():
    st_path = os.getcwd()
    template_file = os.path.join(os.getcwd(), "client.conf.in")
    with open(template_file, "r", encoding="utf-8", errors="ignore") as template:
        with open(os.path.join(st_path, "client/client.conf"), "w") as config_file:
            config_file.write(template.read().replace("${SAMBA_ST_PATH}", st_path))
            config_file.close()


def main(argv):
    # Default samba server url
    host = "//127.0.0.1"
    # Default tests file
    test_file = os.path.join(os.getcwd(), "tests.txt")

    try:
        opts, args = getopt.getopt(argv[1:], "h:f:")
    except getopt.GetoptError:
        sys.exit(os.EX_USAGE)
    for opt, arg in opts:
        if opt == '-h':
            host = arg
        if opt == '-f':
            test_file = arg

    # Make config file for smbtorture from template
    make_client_config_file()

    # Load tests list from file
    tests = load_tests(test_file)

    stat = Stat()
    for index, test in enumerate(tests):
        stat.inc(run_test(test, index, len(tests), SmbServer(host=host, path=test.options.server_path)))
    stat.print()


if __name__ == "__main__":
    main(sys.argv)
