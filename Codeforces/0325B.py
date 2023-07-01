import math


n = int(input())

ans = []
p = 0

while pow(2, p) <= n+1:

    a = 1
    b = pow(2, p+1) - 3
    c = -2*n

    sq = int(math.sqrt(b*b - 4*a*c))

    if sq * sq != b*b - 4*a*c:
        sq = sq - 1
    if sq * sq != b*b - 4*a*c:
        sq += 2
        
    if sq*sq == b*b - 4*a*c and (-b + sq) % (2*a) == 0:
        
        x = int((-b + sq)/(2*a))

        # print(x)

        if x > 0 and x%2 == 1:
            ans.append(x * pow(2, p))
        
        x = int((-b -sq)/(2*a))
        if x > 0 and x%2 == 1:
            ans.append(x * pow(2, p))
    p += 1

if len(ans) == 0:
    print(-1)
else:
    for u in ans:
        print(u)