from copy import deepcopy
import random

class Solution:

    def __init__(self, nums: List[int]):
        self.original = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.original

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        nums = deepcopy(self.original)
        ans = []
        while len(nums) > 0:
            idx = random.randint(0, len(nums)-1)
            cur = nums.pop(idx)
            ans.append(cur)
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()