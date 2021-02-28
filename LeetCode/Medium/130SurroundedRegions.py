class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) <= 2 or len(board[0]) <= 2: return
        # dfs (flip all Os connected to Zs on the border)
        def dfs(i, j):
            if i not in range(len(board)) or j not in range(len(board[0])): return
            if board[i][j] in ['Z', 'X']: return
            board[i][j] = 'Z'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
            return

        for i in [0, len(board)-1]:
            for j in range(len(board[0])):
                dfs(i,j)
        for i in range(len(board)):
            for j in [0, len(board[0])-1]:
                dfs(i,j)

        # modify board
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O': board[i][j] = 'X'
                elif board[i][j] == 'Z': board[i][j] = 'O'
        return
