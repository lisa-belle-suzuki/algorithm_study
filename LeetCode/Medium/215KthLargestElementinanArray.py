import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # solution1: sort
        # nums.sort(reverse=True)
        # return nums[k-1]

        # solution2: heap
        nums_new = [-num for num in nums]
        heapq.heapify(nums_new)
        for _ in range(k):
            ret = heapq.heappop(nums_new)
        return -ret
