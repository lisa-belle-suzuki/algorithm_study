from heapq import heapify, heappop


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        heapify(nums)
        ret = []
        prev = heappop(nums)
        while nums:
            cur = heappop(nums)
            if prev == cur:
                ret.append(cur)
            prev = cur

        return ret
