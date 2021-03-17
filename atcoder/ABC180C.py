N = int(input())
i = 1
numbers = []
while i * i <= N:
    if N % i == 0:
        numbers.append(i)
        if N//i != i:
            numbers.append(N//i)
    i += 1
numbers.sort()
for num in numbers:
    print(num)
