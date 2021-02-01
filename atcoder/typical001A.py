from collections import deque

# maze = [
#     '########',
#     '#......#',
#     '#.######',
#     '#..#...#',
#     '#..##..#',
#     '##.....#',
#     '########'
# ]

# s_i, s_j = 1,1
# g_i, g_j = 3,4

H,W = list(map(int, input().split()))
s_i, s_j = list(map(int, input().split()))
g_i, g_j = list(map(int, input().split()))
maze = []
for _ in range(int(H)):
    maze.append(input())
s_i -= 1
s_j -= 1
g_i -= 1
g_j -= 1

visited = [ [False] * W for _ in range(H) ]

def solve():
    q = deque()
    q.append((s_i,s_j,0))

    while q:
        cur = q.popleft()
        i,j,cnt = cur
        if visited[i][j]:
            continue
        if i<0 or i>=H or j<0 or j>=W:
            continue
        if maze[i][j]=='#':
            continue
        if i==g_i and j==g_j:
            return cnt
        q.append((i+1, j, cnt+1))
        q.append((i-1, j, cnt+1))
        q.append((i, j+1, cnt+1))
        q.append((i, j-1, cnt+1))
        visited[i][j] = True
    return -1

if __name__=='__main__':
    print(solve())