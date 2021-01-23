class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums)==1:
            return nums
        nums.sort()
        print("sorted_nums = ", nums)
        ans_indice = []
        if len(nums) % 2 == 0:
            i = len(nums)//2-1
            while i >=0 :
                ans_indice.append(i)
                ans_indice.append(i + len(nums)//2)
                i -= 1
        else:
            if nums[len(nums)//2] == nums[len(nums)//2 + 1]:
                for i in range(len(nums)//2):
                    ans_indice.append(i)
                    ans_indice.append(i + len(nums)//2 + 1)
                ans_indice.append(len(nums)//2)
            else:
                i = len(nums)//2 -1
                while i>= 0:
                    ans_indice.append(i)
                    ans_indice.append(i + len(nums)//2 + 1)
                    i -= 1
                ans_indice.append(len(nums)//2)
        ans = []
        for i in range(len(ans_indice)):
            ans.append(nums[ans_indice[i]])
        for i in range(len(nums)):
            nums[i] = ans[i]
