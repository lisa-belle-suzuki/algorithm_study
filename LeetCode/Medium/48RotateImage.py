class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        if N%2==0:
            i_max = j_max = N//2
        else:
            i_max = N//2
            j_max = i_max + 1
        for i in range(i_max):
            for j in range(j_max):
                numbers = [
                    matrix[i][j],
                    matrix[j][N-i-1],
                    matrix[N-i-1][N-j-1],
                    matrix[N-j-1][i]
                ]
                matrix[i][j] = numbers[3]
                matrix[j][N-i-1] = numbers[0]
                matrix[N-i-1][N-j-1] = numbers[1]
                matrix[N-j-1][i] = numbers[2]
        return
