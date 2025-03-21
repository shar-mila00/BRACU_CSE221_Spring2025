import sys

def binaryTree(arr, low, high, result):
    if low > high:
        return
    mid = (low + high)//2
    result.append(arr[mid])

    binaryTree(arr, low, mid - 1, result)
    binaryTree(arr, mid+1, high, result) 

def binary(arr, N):
    result = []
    binaryTree(arr, 0, int(N)-1, result)
    return result    


N = sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))
resultArr = binary(arr, N)
sys.stdout.write(" ".join(map(str, resultArr))) 