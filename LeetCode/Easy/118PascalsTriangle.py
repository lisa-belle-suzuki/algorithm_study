class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        
        ans = []
        ans.append([1])
        prev = [1]
        for i in range(2, numRows+1):
            cur = []
            for j in range(i):
                if j == 0 or j == i-1:
                    n = prev[0]
                else:
                    n = prev[j-1] + prev[j]
                cur.append(n)
            ans.append(cur)
            prev = cur
        return ans
