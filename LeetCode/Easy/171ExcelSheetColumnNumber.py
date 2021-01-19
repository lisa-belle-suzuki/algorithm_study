class Solution:
    def titleToNumber(self, s: str) -> int:
        # 1文字のとき
        #   ord()をとって, - ord("A") + 1

        # 2文字のとき
        #   1文字目: 26進数の十の位
        #   2文字目: 26進数の十の位

        # n文字のとき
        #   1文字目: 26進数の一番上の位
        #   ...
        #

        prev = 0
        for i in range(len(s)):
            c = s[i]
            num = ord(c) - ord("A") + 1
            prev = prev * 26 + num

        return prev
