class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        cnt = {}
        for num in nums:
            if num in cnt:
                return True

            cnt[num] = 1

        return False
