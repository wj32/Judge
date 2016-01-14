# Python 3

from fractions import gcd
from sys import stdin

t = int(stdin.readline())

for i in range(t):
    l, b = [int(x) for x in stdin.readline().split()]
    print(int(l * b / gcd(l, b) ** 2))
