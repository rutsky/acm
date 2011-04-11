#!/usr/bin/env python2.5

import sys

for num in map(int, sys.stdin.read().split()):
    if num == 42:
        break
    print num
