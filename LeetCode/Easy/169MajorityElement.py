class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()

        cur_num = None
        cur_max = 0
        cur_cnt = 0
        max_num = None
        for i in range(len(nums)):
            if i == 0:
                cur_num = nums[i]
                cur_cnt = 1
            else:
                if nums[i] == nums[i-1]:
                    cur_cnt += 1
                else:
                    if cur_cnt > cur_max:
                        cur_max = cur_cnt
                        max_num = cur_num
                    cur_num = nums[i]
                    cur_cnt = 1

        if cur_cnt > cur_max:
            cur_max = cur_cnt
            return nums[-1]

        return max_num
