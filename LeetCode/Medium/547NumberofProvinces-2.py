from collections import defaultdict

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        uf = UnionFind(N)

        for from_ in range(N-1):
            for to_ in range(from_+1, N):
                if isConnected[from_][to_] and (from_!=to_):
                    uf.union(from_, to_)

        visited = [False] * N
        cnt = 0
        for i in range(N):
            if visited[i]:
                continue
            parent = uf.find(i)
            if not visited[parent]:
                cnt += 1
                visited[parent] = True
        return cnt
