def factorial(n):
    if not n:
        return 1
    return factorial(n-1)*n
def pow2(n):
    if not n:
        return 1
    return pow2(n-1)+pow2(n-1)
print(factorial(5))
print(pow2(5))
def hanoi(n,source,dest,other):
    if n==1:
        dest.append(source.pop())
        print(source,dest,other)
    else:
        hanoi(n-1,source,other,dest)
        dest.append(source.pop())
        print(source, dest, other)
        hanoi(n-1,other,dest,source)
hanoi(3,["C","B","A"],[],[])