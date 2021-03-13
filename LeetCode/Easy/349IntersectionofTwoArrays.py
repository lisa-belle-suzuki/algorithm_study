class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counter = {}
        for num in nums1:
            if num not in counter:
                counter[num] = True

        ans = []
        for num in nums2:
            if num in counter:
                ans.append(num)
                counter.pop(num)
        return ans
