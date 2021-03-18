X, K, D = map(int, input().split())


X = abs(X)

# K回以内でDまで近づけるか
decrease = min(K, X // D)
K -= decrease
X -= D * decrease
if K == 0:
    print(X)
else:
    if K % 2 == 0:
        print(X)
    else:
        print(abs(X-D))
