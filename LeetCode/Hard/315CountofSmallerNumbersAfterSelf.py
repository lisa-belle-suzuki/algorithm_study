from bisect import bisect_left, insort

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        to_copy = list()
        ans = list()
        for num in nums[::-1]:
            equal_or_bigger_idx = bisect_left(to_copy, num, 0, len(to_copy))
            ans.append(equal_or_bigger_idx)
            insort(to_copy, num)
        return ans[::-1]
