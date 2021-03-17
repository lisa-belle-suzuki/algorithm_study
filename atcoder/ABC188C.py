N = int(input())
A = list(map(int, input().split()))
pair_list = []


for i, a in enumerate(A):
    pair_list.append([i, a])

length = len(pair_list)

while length > 2:
    for i in range(length//2):
        if pair_list[2*i][1] > pair_list[2*i+1][1]:
            pair_list[i] = pair_list[2*i]
        else:
            pair_list[i] = pair_list[2*i+1]
    length //= 2


if pair_list[0][1] < pair_list[1][1]:
    print(pair_list[0][0] + 1)
else:
    print(pair_list[1][0] + 1)
