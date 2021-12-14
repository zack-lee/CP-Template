#!/usr/bin/env python3
import sys
import glob
import os
from shutil import copyfile

#1 args is make n many right there
#2 args is make n many in directory specified
def main():
    f1 = '/home/zlee/CP-Template/template.cpp'
    f2 = '/home/zlee/CP-Template/main.cpp'
    dirname = ""
    makedir = False
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
    elif len(sys.argv) == 3:
        n = int(sys.argv[1])
        dirname = str(sys.argv[2])
        dirname += "/"
        makedir = True
    else:
        exit()
    monka = True
    if makedir:
        os.makedirs("{}".format(dirname), exist_ok=True)
    for i in range(n):
        if os.path.exists("{}{}.cpp".format(dirname, chr(i+65))) and monka:
            print("File already exists! Press y to overwrite".format(i))
            if input() == "y":
                monka = False
            else:
                exit()
        with open("{}{}.cpp".format(dirname, chr(i+65)), "w") as f, open(f1,'r') as F1, open(f2,'r') as F2:
            for line in F1:
                f.write(line)
            for line in F2:
                f.write(line)

main()
