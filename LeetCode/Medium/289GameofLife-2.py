class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        d = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
        for i in range(len(board)):
            for j in range(len(board[0])):
                cur = board[i][j]
                around_sum = 0
                for di,dj in d:
                    around_i = i + di
                    around_j = j + dj
                    if 0<=around_i<len(board) and 0<=around_j<len(board[0]):
                        around = board[around_i][around_j]
                        if around in [0,1]:
                            around_sum += around
                        elif around==2:
                            continue
                        elif around==3:
                            around_sum += 1
                if cur==0:
                    if around_sum==3: board[i][j] = 2
                elif cur==1:
                    if around_sum not in [2,3]: board[i][j] = 3
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==2:
                    board[i][j] = 1
                elif board[i][j]==3:
                    board[i][j] = 0
        return
