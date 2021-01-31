class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        directions = [[0,1],[1,0],[0,-1],[-1,0]]
        isVisited = [ [False] * len(matrix[0]) for _ in range(len(matrix)) ]
        dir_cnt = 0

        # first cell
        i = 0
        j = 0
        ans = [matrix[i][j]]
        isVisited[i][j] = True
        num_cnt = 1
        while num_cnt < len(matrix)*len(matrix[0]):
            direction = directions[dir_cnt%4]
            i += direction[0]
            j += direction[1]
            while i>=0 and i<len(matrix) and j>=0 and j<len(matrix[0]):
                if isVisited[i][j]:
                    break
                num = matrix[i][j]
                ans.append(num)
                num_cnt += 1
                isVisited[i][j] = True
                i += direction[0]
                j += direction[1]
            i -= direction[0]
            j -= direction[1]
            dir_cnt += 1
        return ans
