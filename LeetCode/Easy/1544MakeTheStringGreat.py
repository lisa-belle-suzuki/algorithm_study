def is_great(char1, char2):
    if char1.islower() and char2.islower(): return False
    if char1.isupper() and char2.isupper(): return False
    if char2.islower():
        if char1.lower()==char2: return True
        else: return False
    else:
        if char1==char2.lower(): return True
        else: return False

class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for c in s:
            stack.append(c)
            while len(stack)>=2:
                if is_great(stack[-2],stack[-1]):
                    stack.pop()
                    stack.pop()
                else:
                    break
        return ''.join(stack)
