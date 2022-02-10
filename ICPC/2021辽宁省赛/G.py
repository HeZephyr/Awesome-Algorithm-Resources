n = int(input())
def judge(n):
    if n >= -128 and n <= 127:
        print("byte")
        return
    if n >= -32768 and n <= 32767:
        print("short")
        return
    if n >= -2147483648 and n <= 2147483647:
        print("int")
        return
    if n >= -9223372036854775808 and n <= 9223372036854775807:
        print("long")
        return
    print("BigInteger")

judge(n)
