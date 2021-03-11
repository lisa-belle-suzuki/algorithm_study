class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = [0] * 60
        for t in time:
            cnt[t % 60] += 1

        def combi_of_pair(num):
            if num < 2:
                return 0
            return (num * (num-1)) // 2

        ans = 0
        for i in range(31):
            if i in [0, 30]:
                ans += combi_of_pair(cnt[i])
            else:
                ans += cnt[i] * cnt[60-i]
        return ans
