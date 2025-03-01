N = int(input())
lis = input().split()

for i in range(len(lis)):
    lis[i] = int(lis[i])

for j in range(N):
    swap = False

    for k in range(0, N-j-1) :
        if lis[k] > lis[k+1]:
            lis[k], lis[k+1] = lis[k+1], lis[k]
            swap = True

    if swap == False:
        break

for c in range(N):
    print(lis[c], end = " ")                