# longest subarray problem

def longestSubArr(size, sum, arr):
    left = 0
    currentSum = 0
    max_size = 0

    for i in range(size):
        currentSum += arr[i]

        while currentSum > sum and left <= i:
            currentSum -= arr[left]
            left += 1

        max_size = max(max_size, i - left + 1)
    return max_size        


line = list(map(int, input().split()))
arr = list(map(int, input().split()))
print(longestSubArr(line[0], line[1], arr))
