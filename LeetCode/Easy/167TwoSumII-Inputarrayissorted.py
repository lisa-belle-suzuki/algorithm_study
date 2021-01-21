class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # # look for complement
        # num_to_idx = {}
        # for i in range(len(numbers)):
        #     num = numbers[i]
        #     complement = target - num
        #     if complement in num_to_idx:
        #         return [num_to_idx[complement][0]+1, i+1]
        #     else:
        #         if num in num_to_idx:
        #             num_to_idx[num].append(i)
        #         else:
        #             num_to_idx[num] = [i]

        # two pointers
        left = 0
        right = len(numbers) - 1
        while left < right:
            calc = numbers[left] + numbers[right]
            if calc == target:
                return [left+1, right+1]
            if calc > target:
                right -= 1
            else:
                left += 1
