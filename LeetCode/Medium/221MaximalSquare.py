from pprint import pprint


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        h = len(matrix)
        w = len(matrix[0])
        tate = [[0] * w for _ in range(h)]
        yoko = [[0] * w for _ in range(h)]

        # yoko
        for i in range(h):
            sum_ = 0
            for j in range(w-1, -1, -1):
                if matrix[i][j] == '0':
                    sum_ = 0
                else:
                    sum_ += int(matrix[i][j])
                yoko[i][j] = sum_

        # tate
        for j in range(w):
            sum_ = 0
            for i in range(h-1, -1, -1):
                if matrix[i][j] == '0':
                    sum_ = 0
                else:
                    sum_ += int(matrix[i][j])
                tate[i][j] = sum_

        # calc
        ans = 0
        for i in range(h):
            for j in range(w):
                rows = tate[i][j]
                cols = yoko[i][j]
                if rows < cols:
                    di = 0
                    min_yoko = rows
                    while di < rows:
                        min_yoko = min(min_yoko, yoko[i+di][j])
                        di += 1
                        ans = max(ans, min(min_yoko, di) ** 2)
                else:
                    dj = 0
                    min_tate = cols
                    while dj < cols:
                        min_tate = min(min_tate, tate[i][j+dj])
                        dj += 1
                        ans = max(ans, min(min_tate, dj) ** 2)
        return ans
