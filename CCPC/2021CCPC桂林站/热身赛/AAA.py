n = int(input())

ans = 1
for i in range(1, n + 1):
    ans *= i
ans *= ans
x = pow(n, n)
y = int(ans / x)
z = 0
print(y, end = '')
print('.', end = '')
ans = ans % x
for i in range(1, 13):
    z = int(ans * 10 / x)
    ans = ans * 10 % x
    print(z, end = '')# 我爱你中国。

