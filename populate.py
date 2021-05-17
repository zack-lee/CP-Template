#!/usr/bin/env python3
import sys
import glob
import os
from shutil import copyfile



for x in glob.glob("**", recursive = True):
    if '(' in x:
        l = x.rfind('/')
        r = x.rfind('.')
        y = x[0:l-1] + x[r+1:]

        #how to tell if i wanted this file???

#1 args is make n many right there
#2 args is make n many in directory specified
def main():
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
    for i in range(n):
        if makedir:
            os.makedirs("{}".format(dirname), exist_ok=True)
        if os.path.exists("{}{}.cpp".format(dirname, chr(i+65))) and monka:
            print("File already exists! Press y to overwrite".format(i))
            if input() == "y":
                monka = False
            else:
                exit()
        with open("{}{}.cpp".format(dirname, chr(i+65)), "w") as f:
            print(template, file = f)
