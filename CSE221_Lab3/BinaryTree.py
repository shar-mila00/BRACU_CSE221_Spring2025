def balanced_bst_order(arr):
    def construct_balanced_order(start, end):
        if start > end:
            return []
        mid = (start + end) // 2
        return [arr[mid]] + construct_balanced_order(start, mid - 1) + construct_balanced_order(mid + 1, end)
    
    return construct_balanced_order(0, len(arr) - 1)

# Read input
N = int(input())
A = list(map(int, input().split()))

# Get the order and print it
print(*balanced_bst_order(A))
