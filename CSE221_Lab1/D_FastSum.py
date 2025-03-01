T = int(input())
lis = []
for i in range(T):
    N = int(input())
    sum = int((N*(N+1))/2)
    lis.append(sum)

for j in range(len(lis)):
    print(lis[j])    