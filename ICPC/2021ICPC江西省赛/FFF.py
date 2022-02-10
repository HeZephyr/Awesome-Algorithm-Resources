
f = list()
f.append(0)
f.append(1)
for i in range(2, 10001):
    f.append(1000000000000000000000000000000000000000000000000000000)
    for j in range(0, min(i, 1000)):
        f[i] = min(f[i - j], f[j] + pow(2, j) - 1)
        
t = int(input())
for i in range(0, t):
    n = int(input())
    print(f[n])
