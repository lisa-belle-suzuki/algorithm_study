class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums)==1:
            return nums
        nums.sort()
        # [1,5,1,1,6,4]
        # [1,1,1,   4,5,6,]
        # [1,6, 1,5,  1,4]
        ans_indice = []
        if len(nums) % 2 == 0:
            i = len(nums)//2-1
            while i >=0 :
                ans_indice.append(i)
                ans_indice.append(i + len(nums)//2)
                i -= 1
        else:
            # [1,1,1,1,4,5,6]
            # [1,1,1,  1,   4,5,6]
            # [1,6,  1,5,  1,4,  1]

            # [1,1,1,4,4,5,6]
            # [1,1,1, 4, 4,5,6]
            # x [1,6,  1,5,  1,4  ,4]
            # o [1,4,  1,5,  1,6,  4]
            for i in range(len(nums)//2):
                ans_indice.append(i)
                ans_indice.append(i + len(nums)//2 + 1)
            ans_indice.append(len(nums)//2)

        ans = []
        for i in range(len(ans_indice)):
            ans.append(nums[ans_indice[i]])
        for i in range(len(nums)):
            nums[i] = ans[i]