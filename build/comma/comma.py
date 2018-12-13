#!/usr/bin/env python3

import collections
import decimal
import fractions
import functools
import heapq
import itertools
import math
import random
import re
import sys

### Helpers ###

def readline():
    return sys.stdin.readline().strip()

def readlines():
    return sys.stdin.readlines().strip()

def read_intline():
    return list(map(int, readline().split()))

def read_floatline():
    return list(map(float, readline().split()))

memoize = functools.lru_cache

def clear(x):
    return x.replace('.', '').replace(',', '')

def canAdd(x):
    return (not x[-1]=='.' and not x[-1]==',')

### Implementation ###
def main():
    '''Solution for problem: XXX

    Written by: ZZZ

    Date: YYYY-MM-DD

    Lessons learned: TEXTTEXTTEXT

    '''
    line = readline()
    before, after = {}, {}

    words = line.split(', ');
    last = len(words)-1
    for i in range(len(words)):
        if i > 0:
            after[clear(words[i-1].split(' ')[-1])] = True
        if i < len(words)-1:
            before[clear(words[i+1].split(' ')[0])] = True
    words = line.split(' ')

    changed = True
    while changed:
        changed = False
        for i in range(len(words)):
            if before.get(clear(words[i])) and i > 0 and canAdd(words[i-1]):
                changed = True
                after[words[i-1]] = True
                words[i-1]+=','

            if after.get(words[i]) and canAdd(words[i]):
                if i < len(words)-1:
                    changed = True
                    before[clear(words[i+1])] = True
                words[i]+=','
    print(" ".join(words))

if __name__ == '__main__':
    main()
