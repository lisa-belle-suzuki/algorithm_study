class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left == right:
            return left

        l = bin(left)[2:]
        r = bin(right)[2:]
        if len(l) < len(r):
            l = '0' * (len(r)-len(l)) + l
        else:
            r = '0' * (len(l)-len(r)) + r

        ans = ''
        foundDiff = False
        for L, R in zip(l, r):
            if foundDiff:
                ans += '0'
                continue
            if L == R == '1':
                ans += '1'
            elif L == R == '0':
                ans += '0'
            else:
                ans += '0'
                foundDiff = True

        def str2bin(s):
            ret = 0
            for c in s:
                if c == '1':
                    ret += 1
                ret *= 2
            return ret // 2

        return str2bin(ans)
