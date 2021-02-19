class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        N = len(nums)
        if N==1: return 0
        for i in range(N):
            if i==0:
                if nums[0] > nums[1]: return 0
            elif i==N-1:
                if nums[N-1] > nums[N-2]: return N-1
            else:
                if nums[i] > nums[i-1] and \
                    nums[i] > nums[i+1]:
                    return i
        return -1
