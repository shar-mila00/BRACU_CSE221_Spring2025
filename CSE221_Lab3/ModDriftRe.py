import sys

def geometric_sum(a, n, m):
    
    if a == 1:
        return n % m  # Base case: S(1) = a % m
    else:
        mod = m*(a - 1)
        ex = n + 1
        a_p = pow(a, ex, mod)
        num = (a_p - a) % mod
        sum = num // (a - 1)
        return sum % m
     

T = sys.stdin.readline()

results = []

for _ in range(int(T)):
    a, n, m = map(int, sys.stdin.readline().split())
    results.append((geometric_sum(a, n, m)))


sys.stdout.write("\n".join(map(str, results)) + "\n")
