#!/usr/bin/python3

import sys, getopt, os, errno

def main(argv):
    passdbFile = os.getcwd() + "/kos/resources/ramfs/usr/local/samba/private/passdb.tdb"
    print(passdbFile)

    privateDirName = "/private"

    folderName = ''
    try:
        opts, args = getopt.getopt(argv,"f:", ["folder="])
    except getopt.GetoptError:
        sys.exit(2)
    for opt, arg in opts:
        if opt in ("-f", "--folder"):
            folderName = arg

    privateDirName = folderName.rpartition("/")[0] + privateDirName

    try:
        os.mkdir(folderName)
        os.mkdir(folderName + "2")
        os.mkdir(privateDirName)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise
        else:
            exit(0)

    os.chmod(folderName, 0o777)
    os.chmod(folderName + "2", 0o777)
    os.chmod(privateDirName, 0o755)

    os.system("cp " + passdbFile + " " + privateDirName)  

    try:
        contName = folderName.rpartition("/")[0] + "/smb.conf"
        folderName
        conf = open(contName, "w")
        confText = ''

        confText += "[global]\n"
        confText += "map to guest = bad user\n"
        confText += "workgroup = WORKGROUP\n"
        confText += "server string = Samba Server\n"
        confText += "server role = standalone server\n"
        confText += "log file = ./log.%m\n"
        confText += "max log size = 50\n"
        confText += "dns proxy = no\n"
        confText += "disable netbios = yes\n"
        confText += "smb ports = 1490\n"
        confText += "log level = 5\n"
        confText += "lock directory = " + privateDirName + "\n"
        confText += "private dir = " + privateDirName + "\n"
        confText += "restrict anonymous = 2\n"
        confText += "valid users = @user, @root\n"
        confText += "server min protocol = SMB2_10\n"
        confText += "server max protocol = SMB2_10\n"

        confText += "[tmp]\n"
        confText += "path=" + folderName + "\n"
        confText += "public = yes\n"
        confText += "browseable = yes\n"
        confText += "writable = yes\n"
        confText += "guest ok = no\n"
        confText += "read only = no\n"

        confText += "[tmp2]\n"
        confText += "path=" + folderName + "2\n"
        confText += "valid users = user, root\n"
        confText += "browseable = yes\n"
        confText += "guest ok = no\n"
        confText += "read only = yes\n"
        confText += "read list = user, root\n"
        confText += "write list = user\n"

        conf.write(confText)
        conf.close
    except FileExistsError as e:
        sys.exit(0)

if __name__ == "__main__":
        main(sys.argv[1:]) 