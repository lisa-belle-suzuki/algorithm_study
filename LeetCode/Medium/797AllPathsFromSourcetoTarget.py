class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []

        def search(visited, cur):
            nonlocal ans
            if cur == len(graph)-1:
                ans.append(visited)
                return
            for node in graph[cur]:
                if node not in visited:
                    search(visited + [node], node)

        search([0], 0)

        return ans
