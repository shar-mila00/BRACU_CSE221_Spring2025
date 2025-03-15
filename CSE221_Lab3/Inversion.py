import sys

def merge(arr, low, mid, end):
    left, right = low, mid+1
    
    # a temporary array
    temp = []
    count = 0 # for counting inversion

    while (left <= mid and right <= end):
        if arr[left] <= arr[right] :
            temp.append(arr[left])
            left += 1
        else :
            temp.append(arr[right])
            right += 1
            count += (mid - left) + 1
    # the remaining part
    while (left <= mid):
        temp.append(arr[left])
        left += 1
    while (right <= end):
        temp.append(arr[right])
        right += 1

    for i in range(len(temp)):
        arr[i + low] = temp[i] 

    return count                   

def mergeSort(arr, low, end):
    if low < end:
        mid = (low + end)//2
        
        # from left side and right side
        leftCount = mergeSort(arr, low, mid)
        rightCount = mergeSort(arr, mid+1, end)

        # inversion count
        invCount = merge(arr, low, mid, end)
        return leftCount + rightCount + invCount
    return 0    



length = sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))
print(mergeSort(arr, 0, int(length) - 1))
sys.stdout.write(" ".join(map(str, arr)))
