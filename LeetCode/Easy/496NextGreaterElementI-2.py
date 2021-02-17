class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [-1] * len(nums1)
        num2_to_greater_map = {}
        stack = []
        for i,num2 in enumerate(nums2):
            if len(stack)==0:
                stack.append(num2)
                continue
            while len(stack)>0:
                top = stack[-1]
                if top >= num2:
                    break
                num2_to_greater_map[top] = num2
                stack.pop()
            stack.append(num2)

        for i,num1 in enumerate(nums1):
            if num1 in num2_to_greater_map:
                ans[i] = num2_to_greater_map[num1]
        return ans
