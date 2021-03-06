class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        num_cnt = defaultdict(int)
        for num in nums:
            num_cnt[num] += 1

        def combi_of_pairs(cnt: int)->int:
            return (cnt * (cnt-1)) // 2

        ans = 0
        for k,v in num_cnt.items():
            if v <= 1: continue
            ans += combi_of_pairs(v)
        return ans
