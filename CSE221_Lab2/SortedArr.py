import sys

# Fast input reading
read = sys.stdin.read
data = read().split()

# Read N and Alice's list
index = 0
N = int(data[index])
index += 1
alice = list(map(int, data[index:index + N]))
index += N

# Read M and Bob's list
M = int(data[index])
index += 1
bob = list(map(int, data[index:index + M]))
index += M

# Two-pointer merge
result = []
i, j = 0, 0

while i < N and j < M:
    if alice[i] <= bob[j]:
        result.append(alice[i])
        i += 1
    else:
        result.append(bob[j])
        j += 1

# Append remaining elements
if i < N:
    result.extend(alice[i:])
if j < M:
    result.extend(bob[j:])

# Fast output
sys.stdout.write(" ".join(map(str, result)) + "\n")
