#!/usr/bin/env python2.5

import sys
import random
import math

def is_prime(m, r):
    """Miller-Rabin primality test.
    See <https://secure.wikimedia.org/wikipedia/en/wiki/Miller%E2%80%93Rabin_primality_test>"""

    #if m == 2 or m == 3:
    #    return True
    #if m == 1 or m % 2 == 0:
    #    return False

    # m - 1 = 2^s * t
    #s = int(math.log(((((m - 2) ^ (m - 1)) + 1) >> 1), 2))
    #t = (m - 1) / (1 << s)

    t = m - 1
    s = 0
    while t % 2 == 0:
        t >>= 1
        s += 1

    # r rounds
    for i in xrange(r):
        a = 2 + int(random.random() * (m - 3))

        x = int(pow(a, t, m))
        if x == 1 or x == m - 1:
            continue
        for j in xrange(s - 1):
            x = (x ** 2) % m
            if x == 1:
                return False
            elif x == m - 1:
                break
        else:
            return False

    return True

inp = list(map(int, sys.stdin.read().split()))
n_tests = inp[0]
assert 0 <= n_tests <= 10
assert (len(inp) - 1) / 2 == n_tests

for test_idx, (m, n) in enumerate(zip(inp[1::2], inp[2::2])):
    assert m <= n
    assert n - m <= 100000

    k = 4

    if m <= 2 <= n:
        print(2)
    if m <= 3 <= n:
        print(3)
    if m <= 5 <= n:
        print(5)
    if m <= 7 <= n:
        print(7)
    if m <= 11 <= n:
        print(11)
    if m <= 13 <= n:
        print(13)
    if m <= 17 <= n:
        print(17)
    if m <= 19 <= n:
        print(19)
    if m <= 23 <= n:
        print(23)
    if m <= 29 <= n:
        print(29)
    if m <= 31 <= n:
        print(31)
    if m <= 37 <= n:
        print(37)
    if m < 38:
        m = 38

    if n > 38:
        for i in xrange(m, n + 1):
            if (i % 2 == 0 or i % 3 == 0 or i % 5 == 0 or i % 7 == 0 or 
                i % 11 == 0 or i % 13 == 0 or i % 17 == 0 or i % 19 == 0 or
                i % 23 == 0 or i % 29 == 0 or i % 31 == 0 or i % 37 == 0):
                continue
            if is_prime(i, k):
                print(i)

    if test_idx + 1 != n_tests:
        sys.stdout.write("\n")

# vim: set ts=4 sw=4 et:
