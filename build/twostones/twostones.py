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
    '''Solution for problem: twostones

    Written by: ZZZ

    Date: 2018-12-14 03:31:21.928750 UTC

    Lessons learned: TEXTTEXTTEXT

    '''
    n = read_intline()[0]
    print("Alice" if n%2 else "Bob")


if __name__ == '__main__':
    main()
