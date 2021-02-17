class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [-1] * len(nums1)
        num2_to_idx_map = {}
        for i,num2 in enumerate(nums2):
            num2_to_idx_map[num2] = i
        for i,num1 in enumerate(nums1):
            num2_idx = num2_to_idx_map[num1]
            for j in range(num2_idx+1, len(nums2)):
                if nums2[j]>num1:
                    ans[i]=nums2[j]
                    break
        return ans
