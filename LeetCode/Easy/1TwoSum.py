class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # # Brute force
        # for i in range(len(nums)-1):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             return [i, j]

        # # look for complement
        # num_to_idx = {}
        # for i in range(len(nums)):
        #     num = nums[i]
        #     if num in num_to_idx:
        #         num_to_idx[num].append(i)
        #     else:
        #         num_to_idx[num] = [i]
        # for i in range(len(nums)):
        #     complement = target - nums[i]
        #     if complement in num_to_idx:
        #         if complement == nums[i] and len(num_to_idx[complement]) > 1:
        #             return num_to_idx[complement][:2]
        #         elif complement != nums[i]:
        #             return [i, num_to_idx[complement][0]]

        # look for complement (one-pass)
        num_to_idx = {}
        for i in range(len(nums)):
            num = nums[i]
            complement = target - num
            if complement in num_to_idx:
                return [i, num_to_idx[complement][0]]
            else:
                num_to_idx[num] = [i]
