class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        if N == 1: return
        if N == 2:
            if k%2==0: return
            else: nums[0], nums[1] = nums[1], nums[0]; return
        k %= N

        if k <= N//2:
            # 右向きに
            for _ in range(k//2):
                last = nums[-1]
                last_second = nums[-2]
                for i in range(N-1, 1, -1):
                    nums[i] = nums[i-2]
                nums[1] = last
                nums[0] = last_second
            if k%2==1:
                last = nums[-1]
                for i in range(N-1, 0, -1):
                    nums[i] = nums[i-1]
                nums[0] = last
        else:
            # 左向きに
            for _ in range((N-k)//2):
                first = nums[0]
                second = nums[1]
                for i in range(N-2):
                    nums[i] = nums[i+2]
                nums[-2] = first
                nums[-1] = second
            if (N-k)%2==1:
                first = nums[0]
                for i in range (N-1):
                    nums[i] = nums[i+1]
                nums[-1] = first
