import bisect
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums)==0:
            return [-1,-1]
        left = bisect.bisect_left(nums, target)
        right = bisect.bisect_right(nums, target)
        if left>=len(nums):
            return [-1,-1]
        if nums[left]==target:
            start = left
            return [start, right-1]
        else:
            return [-1,-1]
