n, m = map(int, input().split())
constraints = []
for _ in range(m):
    c = list(map(int, input().split()))
    constraints.append(c)
k = int(input())
dishes = []
for _ in range(k):
    dish = list(map(int, input().split()))
    dishes.append(dish)

max_cnt = 0


def count(dish_set):
    ret = 0
    for c in constraints:
        if c[0] in dish_set and c[1] in dish_set:
            ret += 1
    return ret


def search(cur_set, i):
    global max_cnt
    if i == k:
        cnt = count(cur_set)
        max_cnt = max(max_cnt, cnt)
        return
    search(cur_set + [dishes[i][0]], i + 1)
    search(cur_set + [dishes[i][1]], i + 1)
    return


search([], 0)

print(max_cnt)
