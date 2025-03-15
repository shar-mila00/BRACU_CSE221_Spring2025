import sys
a, b = map(int, sys.stdin.readline().split())
mod = 107

result = 1
# first take mod of a
a = a % mod

while (b > 0):
    # odd case
    if (b % 2 == 1):
        result = (result*a)%mod
    a = (a*a) % mod
    b //= 2

print(result)        