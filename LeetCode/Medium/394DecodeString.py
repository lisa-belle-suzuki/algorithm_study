class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i, c in enumerate(s):
            print("i=",i)
            if c==']':
                idx = i
                keep = []
                cur = stack.pop()
                while cur != '[':
                    keep.append(cur)
                    cur = stack.pop()
                num = ""
                while stack:
                    cur = stack.pop()
                    if not cur.isdecimal():
                        break
                    num += cur
                if not cur.isdecimal():
                    stack.append(cur)
                print("stack=", stack)
                num = int(num[::-1])
                for _ in range(num):
                    for j in range(len(keep)):
                        stack.append(keep[-1-j])
                print("stack=",stack)
            else:
                stack.append(c)
        return "".join(stack)
