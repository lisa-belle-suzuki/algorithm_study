class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans_reversed = []

        # 1の位
        cur = digits[-1] + 1
        if cur == 10:
            carry = 1 # 繰り上がり
            ans_reversed.append(0)
        else:
            carry = 0
            ans_reversed.append(cur)

        # 後ろから順番に見ていって，繰り上がりをやる
        i = -2
        while i >= -(len(digits)):
            # 足して10なら繰り上がる
            cur = digits[i] + carry
            if cur == 10:
                carry = 1
                ans_reversed.append(0)
            else:
                carry = 0
                ans_reversed.append(cur)
            i -= 1
        if carry != 0:
            ans_reversed.append(1)
        print(ans_reversed)
        return list(reversed(ans_reversed))
