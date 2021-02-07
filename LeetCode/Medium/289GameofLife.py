class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def nextState(me, neighbors) -> int:
            if me == 1:
                if sum(neighbors) in [2,3]:
                    return 1
                else:
                    return 0
            else:
                if sum(neighbors)==3:
                    return 1
                else:
                    return 0

        dis = [-1,0,1]
        djs = [-1,0,1]
        new_board = [ [-1] * len(board[0]) for _ in range(len(board)) ]
        for i in range(len(board)):
            for j in range(len(board[0])):
                cur = board[i][j]
                n_list = []
                for di in dis:
                    for dj in djs:
                        if di==0 and dj==0:
                            continue
                        if 0<=(i+di)<len(board) and 0<=(j+dj)<len(board[0]):
                            n_list.append(board[i+di][j+dj])
                next_cur = nextState(cur, n_list)
                new_board[i][j] = next_cur
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = new_board[i][j]
        return
