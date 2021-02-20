class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        self.nums = nums
        return self.search(0, len(nums)-1)

    def search(self, l, r):
        if not self.nums: return None
        if l==r: return l
        mid = (l+r)//2
        if self.nums[mid] > self.nums[mid+1]:
            return self.search(l, mid)
        return self.search(mid+1, r)
