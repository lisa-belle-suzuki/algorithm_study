class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def flip_to_inf(i, j):
            for row in range(len(matrix)):
                if matrix[row][j] != 0:
                    matrix[row][j] = float('inf')
            for col in range(len(matrix[0])):
                if matrix[i][col] != 0:
                    matrix[i][col] = float('inf')
            return

        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] == 0:
                    flip_to_inf(row, col)

        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] == float('inf'):
                    matrix[row][col] = 0
        return
