H, W, K = map(int, input().split())

C = []
for i in range(H):
    c_list = input().split()
    C.extend(c_list)
# print(C)

i_patterns = []
j_patterns = []


def search_i(idx_list, ptr):
    if ptr == H:
        i_patterns.append(idx_list)
        return
    search_i(idx_list, ptr + 1)
    search_i(idx_list + [ptr], ptr + 1)
    return


def search_j(idx_list, ptr):
    if ptr == W:
        j_patterns.append(idx_list)
        return
    search_j(idx_list, ptr + 1)
    search_j(idx_list + [ptr], ptr + 1)
    return


search_i([], 0)
search_j([], 0)


def count(i_list, j_list):
    ret = 0
    for i in range(H):
        for j in range(W):
            if i in i_list or j in j_list:
                continue
            if C[i][j] == '#':
                ret += 1
    return ret


ans = 0
for i_list in i_patterns:
    for j_list in j_patterns:
        black_cnt = count(i_list, j_list)
        if black_cnt == K:
            ans += 1
print(ans)
