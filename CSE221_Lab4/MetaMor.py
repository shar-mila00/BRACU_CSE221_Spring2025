import sys

vertices = int(input())

input_list = []
for i in range(vertices):
    line = list(map(int, sys.stdin.readline().split()))
    input_list.append(line)

result = [[0]*vertices]*vertices
    

# change the edge valus
for i in range(vertices):
    for j in range(1, len(input_list[i])):
        result[i][input_list[i][j]] = 1

# print
for m in range(vertices):
    for n in range(vertices):
        # print(result[m][n], end = " ")

        if n > 0 and n < len(input_list[m]):
            print(1, end= " ")
        else:
            print(0, end = " ")    
    print()            