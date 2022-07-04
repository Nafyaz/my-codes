x, y, l, r = map(int, input().split())

xpow, ypow = [1], [1]
for i in range(70):
    xpow.append(xpow[-1] * x)
    ypow.append(ypow[-1] * y)

unlucky = [xp + yp for xp in xpow for yp in ypow if (l <= xp+yp and xp+yp <= r)] 
unlucky = list(set(unlucky))
unlucky.sort()

if(len(unlucky) == 0): 
    print(r - l + 1)
    quit()
 
last = l - 1
ans = 0
for val in unlucky:
    ans = max(ans, val - last - 1)
    last = val

ans = max(ans, r - unlucky[-1])
 
print(ans)