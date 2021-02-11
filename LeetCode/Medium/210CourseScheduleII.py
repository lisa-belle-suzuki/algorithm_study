from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {}
        indeg = [0] * numCourses
        visited = [False] * numCourses

        for pre in prerequisites:
            to_, from_ = pre
            if from_ not in graph:
                graph[from_] = [to_]
            else:
                graph[from_].append(to_)
            indeg[to_] += 1

        ans = []
        def bfs(node):
            q = deque()
            q.append(node)
            while q:
                u = q.popleft()
                visited[u]=True
                print("u=",u)
                ans.append(u)
                if u not in graph:
                    continue
                for adja in graph[u]:
                    indeg[adja] -= 1
                    if visited[adja]==False and indeg[adja]==0:
                        q.append(adja)
                        visited[adja]=True

        for i in range(numCourses):
            if indeg[i]==0 and visited[i]==False:
                bfs(i)

        if len(ans)!=numCourses:
            return []
        return ans
