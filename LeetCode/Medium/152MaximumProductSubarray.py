class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        def solve(numbers):
            dp = [ [float('inf')] * (len(numbers) + 2) for _ in range(len(numbers) + 2) ]
            cur_max = -float('inf')
            isZero = set()
            for i in range(len(numbers)):
                for j in range(i+1, len(numbers)+1):
                    if i in isZero:
                        break
                    if i+1 == j:
                        cur = numbers[i]
                    else:
                        cur = dp[i][j-1] * numbers[j-1]
                    dp[i][j] = cur
                    if cur > cur_max:
                        cur_max = cur
                    if cur == 0:
                        isZero.add(i)
            return cur_max

        return solve(nums)
