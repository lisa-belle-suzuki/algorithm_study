class LargerNumStr(str):
    def __lt__(x,y):
        return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums_iter = map(str, nums)
        sorted_nums = ''.join( sorted(nums_iter, key=LargerNumStr) )
        if sorted_nums[0]=='0': return '0'
        else: return sorted_nums
