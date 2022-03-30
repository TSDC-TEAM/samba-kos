#!/usr/bin/python3

import sys, getopt, os, errno

def printUsage():
    print(__file__ + " -s [path_to_smbclient]")

def main(argv):
    print(argv)

    if (len(argv) < 2):
        printUsage()
        exit(1)

    folderName = ''
    try:
        opts, args = getopt.getopt(argv, "f:h")
    except getopt.GetoptError:
        exit(2)
    for opt, arg in opts:
        if opt in ("-f"):
            folderName = arg
        if opt in ("-h"):
            printUsage()
            exit(1)

    print(folderName)

if __name__ == "__main__":
        main(sys.argv[1:]) 