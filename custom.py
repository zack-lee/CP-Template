#!/usr/bin/env python3
import sys
import glob
import os
from shutil import copyfile

libs = []
for x in glob.glob("**", recursive = True):
    if '.' in x:
        l = x.rfind('/')
        r = x.rfind('.')
        name = x[l+1:r]
        lib.append((name, x))

f1 = 'template.cpp'
f2 = 'main.cpp'
if len(sys.argv) < 2:
    print("Not enough arguments")
    exit()

dest = "{}.cpp".format(sys.argv[1])
for arg in sys.argv[2:]:
    ahhh

print(dest)
if os.path.exists(dest) and monka:
    print("File already exists! Press y to overwrite".format(i))
    if input().lower() != "y":
        exit()

    for line in F1:
        f.write(line)
    for line in F2:
        f.write(line)
