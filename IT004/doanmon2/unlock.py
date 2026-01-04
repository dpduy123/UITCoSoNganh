import math 

n, k = map(int,input().split()) 
a = []
for _ in range(5): 
    a.append(list(map(int,input().split())))
mp = {}

for i0 in range(n):
    if (a[0][i0] not in mp):
        mp[a[0][i0]] = 1
    else:
        mp[a[0][i0]] += 1 

res = 0 
for i1 in range(n): 
    for i2 in range(n):
        for i3 in range(n):
            for i4 in range(n): 
                sum = a[1][i1] + a[2][i2] + a[3][i3] + a[4][i4] 
                if ((k - sum) in mp):
                    res += mp[k - sum]
print(res)
