class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        visited = [False] * N

        def search(start):
            visited[start] = True
            for to in range(N):
                if to != start and isConnected[start][to] and not visited[to]:
                    search(to)
            return

        cnt = 0
        for i in range(N):
            if not visited[i]:
                search(i)
                cnt += 1
        return cnt
