import sys

def pairSum(arr, low, mid, high):
    # maximum value
    left = -float('inf')
    for i in range(low, mid+1):
        left = max(left, arr[i])
    right = -float('inf')    
    for j in range(mid+1, high+1):
        right = max(right, arr[j]**2)

    return left + right

def division(arr, low, high):
    if low == high:
        return -float('inf')
    else:
        mid = (low + high)//2
        leftSum = division(arr, low, mid)
        rightSum = division(arr, mid+1, high)
        crossSum = pairSum(arr, low, mid, high)

        return max(leftSum, rightSum, crossSum)

length = sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))
#arr = list(map(abs, arr))
print(division(arr, 0, int(length)-1))