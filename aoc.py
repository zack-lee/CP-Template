import requests
session = "53616c7465645f5f83754461c780947c8f03f692e4ec74aca83ac23aa1cb35f8a5301218f051099c5e7a71da5f028cda"

def getday(n):
    return requests.get(f"https://adventofcode.com/2021/day/{n}/input",cookies={'session':session}).text

from itertools import product as T, permutations as P, combinations as C
import copy
from functools import cache

#requires defined n/m
def inside(x,y):
    return 0 <= x and x < n and 0 <= y and y < m

def ARR(*args):
    if len(args) == 2:
        return [args[0] for _ in R(args[1])]
    else:
        return [ARR(args[0], *args[2:]) for _ in R(args[1])]

L = getday(1).split("\n")[:-1]