class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums2 = [-1] + sorted(nums)
        ans = []
        def search(num):
            l = 0
            r = len(nums2)-1
            while l <= r:
                c = (l+r)//2
                if nums2[c]>=num:
                    r = c-1
                    continue
                if nums2[c+1]<num:
                    l = c+1
                    continue
                else:
                    # nums2[c]<num
                    return c
            return -1

        for num in nums:
            max_smaller_idx = search(num)
            ans.append(max_smaller_idx)
        return ans
