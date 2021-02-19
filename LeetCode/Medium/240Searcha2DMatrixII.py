class Solution:
    def search_col(self, i):
        if not self.matrix or not self.target: return None
        l = 0
        r = len(self.matrix[0])-1
        while l<=r:
            c = (l+r)//2
            if self.matrix[i][c]==self.target: return True
            elif self.matrix[i][c]>self.target: r = c-1
            elif self.matrix[i][c]<self.target: l = c+1
        return False

    def search_row(self, j):
        if not self.matrix or not self.target: return None
        l = 0
        r = len(self.matrix)-1
        while l<=r:
            c = (l+r)//2
            if self.matrix[c][j]==self.target: return True
            elif self.matrix[c][j]>self.target: r = c-1
            elif self.matrix[c][j]<self.target: l = c+1
        return False

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        self.target = target
        self.matrix = matrix
        H = len(matrix)
        W = len(matrix[0])
        if H > W:
            # rowをlog取りたい
            for i in range(H):
                if self.search_col(i): return True
            return False
        else:
            # colをlog取りたい
            for j in range(W):
                if self.search_row(j): return True
            return False
