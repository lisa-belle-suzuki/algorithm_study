class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        count = defaultdict(int)
        for c in s:
            count[c] += 1

        isOdd = False
        for k in count.keys():
            if count[k] % 2 == 0:
                continue
            if isOdd:
                return False
            isOdd = True
        return True
