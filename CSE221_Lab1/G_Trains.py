n = int(input())
record = []

for i in range(n):
    data = input().strip()
    data = data.split(" ")

    record.append((data[0], data[4], data[6]))

#sorting

for j in range(n):
    for k in range(n-j-1):
        t1 = record[k]
        t2 = record[k+1]

        if t1[0] > t2[0] or (t1[0] == t2[0] and t1[2] < t2[2]):
            record[k], record[k+1] = record[k+1], record[k]

#output
for m in range(n):
    print(f"{record[m][0]} will departure for {record[m][1]} at {record[m][2]}")             