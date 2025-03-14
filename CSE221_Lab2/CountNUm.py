import sys
import bisect

# Read input
n, q = map(int, sys.stdin.readline().split())  # Read n and q
arr = list(map(int, sys.stdin.readline().split()))  # Read sorted array

results = []  # Store results for faster output

for _ in range(q):
    x, y = map(int, sys.stdin.readline().split())  # Read each query
    lower = bisect.bisect_left(arr, x)  # First index where arr[i] >= x
    upper = bisect.bisect_right(arr, y)  # First index where arr[i] > y
    results.append(str(upper - lower))  # Compute count

# Print all results in one go (faster than multiple print calls)
sys.stdout.write("\n".join(results) + "\n")
