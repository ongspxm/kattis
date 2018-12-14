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
    '''Solution for problem: timeloop

    Written by: ZZZ

    Date: 2018-12-14 03:38:20.800046 UTC

    Lessons learned: TEXTTEXTTEXT

    '''
    n = read_intline()[0]
    for i in range(n):
        print("%d Abracadabra"%(i+1))

if __name__ == '__main__':
    main()
