class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        R = len(board)
        C = len(board[0])
        # 行
        for i in range(R):
            visited = set()
            for j in range(C):
                num = board[i][j]
                if num == '.': continue
                if num in visited:
                    return False
                else:
                    visited.add(num)
        # 列
        for j in range(C):
            visited = set()
            for i in range(R):
                num = board[i][j]
                if num == '.': continue
                if num in visited:
                    return False
                else:
                    visited.add(num)
        # 9マス
        for i in range(3):
            for j in range(3):
                up = 3 * i
                left = 3 * j
                visited = set()
                for r in range(up, up + 3):
                    for c in range(left, left + 3):
                        num = board[r][c]
                        if num == '.': continue
                        if num in visited:
                            return False
                        else:
                            visited.add(num)

        return True
