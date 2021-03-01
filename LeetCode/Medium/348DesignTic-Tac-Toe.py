class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.board = [ [-1] * n for _ in range(n) ]
        self.n = n

    def isWinningCond(self, r, c, playerNum):
        # たて
        isWinning = True
        for i in range(self.n):
            if self.board[i][c] != playerNum: isWinning = False; break
        if isWinning: return True

        # 横
        isWinning = True
        for i in range(self.n):
            if self.board[r][i] != playerNum: isWinning = False; break
        if isWinning: return True

        # 斜め
        if r == c:
            isWinning = True
            for i in range(self.n):
                if self.board[i][i] != playerNum: isWinning = False; break
            if isWinning: return True

        # 斜め2
        if r+c == self.n-1:
            isWinning = True
            for i in range(self.n):
                if self.board[i][self.n-i-1] != playerNum: isWinning = False; break
            if isWinning: return True

        return False

    def move(self, row: int, col: int, player: int) -> int:
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        """
        self.board[row][col] = player
        if self.isWinningCond(row, col, player): return player
        else: return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)