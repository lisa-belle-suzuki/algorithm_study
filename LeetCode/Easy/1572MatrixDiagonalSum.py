class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        left = 0
        right = 0
        for i in range(len(mat)):
            left += mat[i][i]
            right += mat[i][len(mat)-1-i]
        if len(mat) % 2 == 0:
            return left + right
        else:
            return left + right - mat[len(mat)//2][len(mat)//2]
