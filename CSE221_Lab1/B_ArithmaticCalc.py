N = int(input())
lis = []
for i in range(N):
    exp = input()
   
    for j in range(10, len(exp)):
        ch = exp[j]
        if ch == "+" or ch == "-" or ch == "*" or ch == "/":
            num1 = int(exp[10:j-1])
            op = ch
            num2 = int(exp[j+2:])
            break

    if op == "+":
        lis.append(num1+num2)
    elif op == "-":
        lis.append(num1-num2)
    elif op == "*":
        lis.append(num1*num2)
    elif op == "/":
        lis.append(num1/num2) 
for k in range(N):
    print(lis[k])

                         
