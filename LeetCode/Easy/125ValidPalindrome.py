import string

class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 0:
            return True

        new_s = ""
        for i in range(len(s)):
            if s[i].isalnum():
                new_s += s[i]

        for i in range(len(new_s)//2):
            if new_s[i].lower() != new_s[-(1+i)].lower():
                return False
        return True
