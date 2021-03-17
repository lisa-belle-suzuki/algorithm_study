N, X = input().split()
A = input().split()
ret = []
for a in A:
    if a != X:
        ret.append(a)
print(" ".join(ret))
