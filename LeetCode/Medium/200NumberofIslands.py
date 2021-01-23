class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def search(i, j):
            if isVisited[i][j] or grid[i][j] == '0':
                return
            else:
                print('eee')
                print("[i,j] = [", i, ' ', j, ' ]')
                print("isVisited = ", isVisited[i][j])
                isVisited[i][j] = True
                if i-1 >= 0:
                    search(i-1, j  )
                if i+1 < len(grid):
                    search(i+1, j  )
                if j-1 >= 0:
                    search(i  , j-1)
                if j+1 < len(grid[0]):
                    search(i  , j+1)

        cnt = 0
        isVisited = [ [False] * len(grid[0]) for i in range(len(grid)) ]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and not isVisited[i][j]:
                    print("cnt up")
                    search(i,j)
                    cnt += 1

        return cnt
