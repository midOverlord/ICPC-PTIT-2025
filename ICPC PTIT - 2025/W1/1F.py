t = int(input())
for i in range(0, t) :
    a = int(input())
    b = int(input())
    while b != 0 :
        a, b = b, a % b
    print(a)