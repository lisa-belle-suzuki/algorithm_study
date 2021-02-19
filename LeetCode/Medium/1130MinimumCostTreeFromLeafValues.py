class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        self.memo = {}
        def dp(i,j):
            if i>=j: return 0
            ret = float('inf')
            if (i,j) not in self.memo:
                for k in range(i+1, j+1):
                    ret = min(ret, max(arr[i:k])*max(arr[k:j+1]) + dp(i,k-1) + dp(k,j))
                self.memo[(i,j)] = ret
            return self.memo[(i,j)]

        return dp(0,len(arr)-1)
