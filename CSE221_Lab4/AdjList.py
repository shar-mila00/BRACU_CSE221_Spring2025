import sys
first = sys.stdin.readline().split()
vertices, edges = int(first[0]), int(first[1])

second = list(map(int, sys.stdin.readline().split()))
third = list(map(int, sys.stdin.readline().split()))
fourth = list(map(int, sys.stdin.readline().split()))

adj_list = []

temp, node, weight = 0, 0, 0

for k in range(1, vertices + 1, 1):
    adj_list.append([k])

for i in range(1, edges + 1, 1): 
    temp = second[i - 1]
    node = third[i - 1]
    weight = fourth[i - 1]
    
    adj_list[temp - 1].append((node,weight))

# print out
for j in adj_list:
    print(f"{j[0]}: ", end="")
    for m in range(1, len(j), 1):
        print(j[m], end = " ")
    print()   
