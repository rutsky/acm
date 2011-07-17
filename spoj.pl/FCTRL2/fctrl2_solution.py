#!/usr/bin/env python2.5

import sys

f = [1]
for i in xrange(1, 101):
    f.append(i * f[-1])

inp = map(int, sys.stdin.read().split())
t = inp.pop(0)

assert t == len(inp)

for x in inp:
    print f[x]

# vim: ts=4 sw=4 et:
