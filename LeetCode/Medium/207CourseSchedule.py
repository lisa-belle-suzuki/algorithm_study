from collections import deque
class GraphNode(object):
    def __init__(self):
        self.inDeg = 0
        self.outNodes = []

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(GraphNode)
        totalDeps = 0
        for pre in prerequisites:
            next_c, prev_c = pre[0], pre[1]
            graph[prev_c].outNodes.append(next_c)
            graph[next_c].inDeg += 1
            totalDeps += 1

        nodepCourses = deque()
        for i,node in graph.items():
            if node.inDeg == 0:
                nodepCourses.append(i)

        removedEdges = 0
        while nodepCourses:
            cur = nodepCourses.pop()
            for next_c in graph[cur].outNodes:
                graph[next_c].inDeg -= 1
                removedEdges += 1
                if graph[next_c].inDeg == 0:
                    nodepCourses.append(next_c)
        if removedEdges==totalDeps:
            return True
        else:
            return False
