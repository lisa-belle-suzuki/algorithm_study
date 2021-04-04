class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        row_sum_list = []
        for row in mat:
            s = 0
            row_sum = []
            for cell in row:
                s += cell
                row_sum.append(s)
            row_sum_list.append(row_sum)
        ret = [[0] * len(mat[0]) for _ in range(len(mat))]
        for i in range(len(ret)):
            for j in range(len(ret[0])):
                s = 0
                for i_ in range(max(i-k, 0), min(i+k+1, len(mat))):
                    s += row_sum_list[i_][min(j+k, len(mat[0])-1)]
                    if j-k > 0:
                        s -= row_sum_list[i_][j-k-1]
                ret[i][j] = s

        return ret
