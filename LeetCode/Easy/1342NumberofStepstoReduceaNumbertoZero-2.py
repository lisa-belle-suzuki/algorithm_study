class Solution:
    def numberOfSteps (self, num: int) -> int:
        bin_num = bin(num)[2:]
        ones = bin_num.count('1')
        length = len(bin_num)
        return ones + length - 1
