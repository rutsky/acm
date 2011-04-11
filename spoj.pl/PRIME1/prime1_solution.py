#!/usr/bin/env python2.5

import sys
import random
import math

def exp_mod(a, b, n):
    """Calculates  a^b mod n."""

    a = a % n
    # Loop invariant: 1 = a^b * res
    # Loop ends when  a^b == 1  =>  res == a^b
    res = 1
    while b != 0:
        if b % 2 == 1:
            b = (b - 1)
            res = (res * a) % n
        else:
            b /= 2
            a = (a * a) % n
    return res

def is_prime(m, r):
    """Miller-Rabin primality test.
    See <https://secure.wikimedia.org/wikipedia/en/wiki/Miller%E2%80%93Rabin_primality_test>"""

    if m in [2, 3]:
        return True
    if m == 1:
        return False
    if m % 2 == 0:
        return False

    # m - 1 = 2^s * t
    s = 0
    t = m - 1
    while t % 2 == 0:
        s += 1
        t /= 2

    # r rounds
    for i in xrange(r):
        a = random.randint(2, m - 2)

        x = exp_mod(a, t, m)
        if x == 1 or x == m - 1:
            continue
        for j in xrange(s - 1):
            x = exp_mod(x, 2, m)
            if x == 1:
                return False
            elif x == m - 1:
                break
        else:
            return False

    return True

#print is_prime(7, 20)
#sys.exit()

inp = map(int, sys.stdin.read().split())
n_tests = inp[0]
assert 0 <= n_tests <= 10
assert (len(inp) - 1) / 2 == n_tests

failure_prob = 0.01

for test_idx, (m, n) in enumerate(zip(inp[1::2], inp[2::2])):
    assert m <= n
    assert n - m <= 100000

    #k = int(math.ceil(math.log((n - m + 1) / failure_prob, 4)))
    k = 20

    for i in xrange(m, n + 1):
        if is_prime(i, k):
            print i

    if test_idx + 1 != n_tests:
        print

# vim: set ts=4 sw=4 et:
