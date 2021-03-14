class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ret = [[-1] * n for _ in range(n)]

        direction = 0
        ret[0][0] = 1
        cnt = 2
        i = 0
        j = 0
        while cnt <= (n ** 2):
            if direction == 0:  # right
                j += 1
                while j < n and ret[i][j] == -1:
                    ret[i][j] = cnt
                    cnt += 1
                    j += 1
                j -= 1
                direction = 1
            elif direction == 1:  # down
                i += 1
                while i < n and ret[i][j] == -1:
                    ret[i][j] = cnt
                    cnt += 1
                    i += 1
                i -= 1
                direction = 2
            elif direction == 2:  # left
                j -= 1
                while j >= 0 and ret[i][j] == -1:
                    ret[i][j] = cnt
                    cnt += 1
                    j -= 1
                j += 1
                direction = 3
            else:  # direction == 3  up
                i -= 1
                while i >= 0 and ret[i][j] == -1:
                    ret[i][j] = cnt
                    cnt += 1
                    i -= 1
                i += 1
                direction = 0
        return ret
