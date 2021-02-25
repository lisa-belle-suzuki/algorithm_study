def isNumStr(s: str) -> bool:
    if len(s)==0: return False
    if s[0]=='-':
        return s[1:].isdecimal()
    else:
        return s.isdecimal()

def divide(a, divisor):
    if divisor == 0: raise ValueError("ValueError exception thrown")
    if a == 0: return 0
    return int(a/divisor)


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = []
        for t in tokens:
            if isNumStr(t):
                num_stack.append(int(t))
            else:
                num2 = num_stack.pop()
                num1 = num_stack.pop()
                if t == '+':
                    result = num1 + num2
                elif t == '-':
                    result = num1 - num2
                elif t == '*':
                    result = num1 * num2
                elif t == '/':
                    result = divide(num1, num2)
                num_stack.append(result)
        if len(num_stack) == 1:
            return num_stack.pop()
        return -1
