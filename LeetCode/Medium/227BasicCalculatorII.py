import re

# 塊を数値に変換する
def int_from_chunk(chunk):
    isMultiply = [True]
    nums = re.split('[*/]', chunk)
    for c in chunk:
        if c == '*':
            isMultiply.append(True)
        elif c == '/':
            isMultiply.append(False)
    ret = 1
    for i in range(len(nums)):
        num = int(nums[i])
        if isMultiply[i]:
            ret *= num
        else:
            ret //= num
    return ret

class Solution:
    def calculate(self, s: str) -> int:
        s.replace(' ', '')
        # +,-で区切る
        chunks = re.split('[+-]',s)
        isPlus = [True]
        for c in s:
            if c =='+':
                isPlus.append(True)
            elif c == '-':
                isPlus.append(False)

        # 塊ごとに計算結果を足し合わせる
        ans = 0
        for i in range(len(chunks)):
            chunk = chunks[i]
            chunk_int = int_from_chunk(chunk)
            if isPlus[i]:
                ans += chunk_int
            else:
                ans -= chunk_int
        return ans
