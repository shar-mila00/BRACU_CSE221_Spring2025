n = int(input())
list = []
for i in range(n):
    list.append(int(input()))

for j in range(n):
    if list[j]%2 == 0:
        print(list[j] , " is an Even number.")
    else:
        print(list[j] , " is an Odd number.")        