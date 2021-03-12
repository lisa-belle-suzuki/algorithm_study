class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        sum_ = 0
        map_ = defaultdict(int)
        map_[0] += 1
        for num in nums:
            sum_ += num
            tgt = sum_ - k
            if tgt in map_:
                ans += map_[tgt]
            map_[sum_] += 1
        return ans
