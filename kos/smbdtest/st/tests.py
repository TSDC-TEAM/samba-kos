#!/usr/bin/python3

import sys
import getopt   # FIXME
import os   # FIXME
import collections
from enum import Enum
from colorama import Fore


class Result(Enum):
    UNKNOWN = 0
    PASS = 1
    SKIP = 2
    FAIL = 3


result_codes = {
    "PASS": Result.PASS,
    "SKIP": Result.SKIP,
    "FAIL": Result.FAIL,
}

result_text = {
    Result.PASS: Fore.GREEN + "PASS" + Fore.RESET,
    Result.SKIP: Fore.LIGHTBLACK_EX + "SKIP" + Fore.RESET,
    Result.FAIL: Fore.RED + "FAIL" + Fore.RESET,
    Result.UNKNOWN: Fore.WHITE + "UNKNOWN" + Fore.RESET,
}


def get_result_code(result):
    try:
        return result_codes[result]
    except KeyError:
        return Fore.LIGHTBLACK_EX + "UNKNOWN" + Fore.WHITE


def get_result_text(code):
    try:
        return result_text[code]
    except KeyError:
        return ""


def find_test_result(text):
    return text.find(chr(27) + "[")


def get_test_result(text):
    return get_result_code(text.split(' ')[0][5:-5])


def tests_iterator(file):
    with open(file, "r", encoding="utf-8", errors="ignore") as f:
        for line in f.readlines():
            pos = find_test_result(line)
            if pos > -1:
                line = line[pos:]
                res = get_test_result(line)
                begin = line.find(" ") + 1
                if begin > 0:
                    yield res, line[begin:-1]


class StatGroup(collections.Counter):
    def get_values(self):
        return [
            self.total(),
            self[Result.PASS],
            self[Result.SKIP],
            self[Result.FAIL],
            self.percent()
        ]

    def percent(self):
        try:
            return "{:.2f}".format(self[Result.PASS] / (self.total() - self[Result.SKIP]) * 100)
        except ZeroDivisionError:
            return "-"


class Stat:
    def __init__(self):
        self._groups = dict()
        self._total = StatGroup()

    @staticmethod
    def get_test_group_name(test):
        return test.split('.')[1]

    def _inc_group(self, group, res):
        if group not in self._groups:
            self._groups[group] = StatGroup()
        self._groups[group][res] += 1

    def inc(self, test, res):
        group = Stat.get_test_group_name(test)
        self._inc_group(group, res)
        self._total[res] += 1

    @staticmethod
    def print_line(group, values):
        print("{:60s}{}".format(group, "".join(["{:6s}".format(str(x)) for x in values])))

    def print(self):
        Stat.print_line("", ["TOTAL", "PASS", "SKIP", "FAIL", "%"])
        other = StatGroup()
        for key in self._groups:
            group = self._groups[key]
            if group.total() == 1:
                other += group
            else:
                Stat.print_line(key, group.get_values())
        Stat.print_line("other", other.get_values())
        Stat.print_line("total", self._total.get_values())


def check_argv(argv, count, usage):
    if len(argv) != count:
        print(argv[0] + usage)
        sys.exit()


def action_stat(argv):
    check_argv(argv, 3, "stat <log file name>")

    s = Stat()
    for res, file in tests_iterator(argv[2]):
        s.inc(file, res)
    s.print()


def print_diff(old_result, new_result, file):
    print("{} -> {} {}".format(get_result_text(old_result), get_result_text(new_result), file))


def action_diff(argv):
    check_argv(argv, 4, "diff <old log file> <new log file>")

    old_results = {file: res for res, file in tests_iterator(argv[2])}
    new_results = {file: res for res, file in tests_iterator(argv[3])}
    for file in new_results:
        if file in old_results:
            if old_results[file] != new_results[file]:
                print_diff(old_results[file], new_results[file], file)
        else:
            print_diff(Result.UNKNOWN, new_results[file], file)

    for file in old_results:
        if file not in new_results:
            print_diff(old_results[file], Result.UNKNOWN, file)


def action_filter(argv):
    check_argv(argv, 4, "<PASS|SKIP|FAIL> <log file name>")

    rc = get_result_code(argv[2])
    if rc == Result.UNKNOWN:
        print(argv[0] + "<PASS|SKIP|FAIL> <log file name>")
        sys.exit()

    for res, file in tests_iterator(argv[3]):
        if res == rc:
            print(file)


def main(argv):
    if len(argv) < 2:
        print(argv[0] + "<action> [args]")
        sys.exit()
    globals()["action_" + argv[1]](argv)


if __name__ == "__main__":
    main(sys.argv)
