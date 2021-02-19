class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        left_paren_stack = []
        cnt = 0
        for c in S:
            if c=='(':
                left_paren_stack.append(1)
            elif c==')':
                if len(left_paren_stack)==0:
                    cnt += 1    
                else:
                    left_paren_stack.pop()

        return cnt + sum(left_paren_stack)
