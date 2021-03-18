N = int(input())

visited = set()

for _ in range(N):
    S = input()
    visited.add(S)

print(len(visited))
