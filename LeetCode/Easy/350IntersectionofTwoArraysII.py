class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i = 0
        j = 0
        nums1.sort()
        nums2.sort()
        print(nums1)
        ans = []
        while i < len(nums1) and j < len(nums2):
            num1 = nums1[i]
            num2 = nums2[j]
            if num1 == num2:
                ans.append(num1)
                i += 1
                j += 1
            elif num1 < num2:
                i += 1
            else:
                j += 1

        return ans
