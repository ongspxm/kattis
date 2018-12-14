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
    '''Solution for problem: 3dprinter

    Written by: ZZZ

    Date: 2018-12-14 02:43:08.692295 UTC

    Lessons learned: TEXTTEXTTEXT

    '''
    n = read_intline()[0]
    print(math.ceil(math.log(n, 2)) + 1)

if __name__ == '__main__':
    main()
