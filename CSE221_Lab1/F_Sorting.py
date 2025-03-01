N = int(input())
ID = list(map(int, input().split()))
Marks = list(map(int, input().split()))
swap = 0

student = []
for i in range(N):
    student.append((ID[i], Marks[i]))

for j in range(N-1):
    max = j
    for k in range(j+1, N):
        if student[k][1] > student[max][1] or (student[k][1] == student[max][1] and student[k][0] < student[max][0]):
            max = k 
    if max != j:
        student[j], student[max] = student[max], student[j]
        swap += 1            

print(f"Minimum swaps: {swap}")

for c in student:
    print(f"ID: {c[0]} Mark: {c[1]}")
           