class Solution:
    def __init__(self):
        self.area = 0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        H = len(grid)
        W = len(grid[0])
        visited = [ [False] * W for _ in range(H) ]
        di_dj_set = ((1,0),(0,-1),(-1,0),(0,1))
        def search(i,j):
            global area
            if not (0<=i<H) or not (0<=j<W): return
            if visited[i][j]: return
            if grid[i][j]==0: return
            visited[i][j] = True
            self.area += 1
            for di,dj in di_dj_set: search(i+di,j+dj)
            return

        max_area = 0
        for i in range(H):
            for j in range(W):
                if not visited[i][j] and grid[i][j]==1:
                    print("i=",i,"j=",j)
                    self.area = 0
                    search(i,j)
                    if self.area > max_area: max_area = self.area

        return max_area
