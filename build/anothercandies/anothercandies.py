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


### Implementation ###


def main():
    '''Solution for problem: anothercandies

    Written by: ZZZ

    Date: 2018-12-14 04:53:02.482042 UTC

    Lessons learned: TEXTTEXTTEXT

    '''
    N = read_intline()[0]
    readline()
    for n in range(N):
        tot = 0
        x = read_intline()[0]

        for i in range(x):
            tot += read_intline()[0]
        readline()

        print("YES" if tot%x == 0 else "NO")

if __name__ == '__main__':
    main()
