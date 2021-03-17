N = int(input())
N -= 1


if (N-11) < 11:
    divided = 1
    divisor = 1
    for i in range(N-11):
        divided *= (N-i)
        divisor *= (i+1)
    print(divided // divisor)
else:
    divided = 1
    divisor = 1
    for i in range(11):
        divided *= (N-i)
        divisor *= (i+1)
    print(divided // divisor)
