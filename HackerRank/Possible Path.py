# Python 3

from fractions import gcd
from sys import stdin

t = int(stdin.readline())

def testCase(a, b, x, y):
    gcd1 = gcd(a, b)
    gcd2 = gcd(x, y)
    if gcd1 == gcd2:
        print("YES")
    else:
        print("NO")

for i in range(t):
    testCase(*([int(x) for x in stdin.readline().split()]))
