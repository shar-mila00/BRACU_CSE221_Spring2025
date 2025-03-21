import sys
def postOrder(arr, low, high, order):
    if low > high:
        return
    
    mid = (low + high)//2

    # left -> right -> root
    postOrder(arr, low, mid-1, order)
    postOrder(arr, mid + 1, high, order)
    order.append(arr[mid])

def binary(inOrder, preOrder, N):

    # getting root in inOrder
    root = 0

    for i in range(int(N)):
        if inOrder[i] == preOrder[0]:
            root = i
            break

    post_order = []
    postOrder(inOrder, 0, root-1, post_order)
    postOrder(inOrder, root + 1, int(N)-1, post_order)
    post_order.append(inOrder[root])

    return post_order
        


N = sys.stdin.readline()
inOrder = list(map(int, sys.stdin.readline().split()))
preOrder = list(map(int, sys.stdin.readline().split()))
post_order = binary(inOrder, preOrder, N)
sys.stdout.write(" ".join(map(str, post_order)))