class Solution:
    def typed_str_stack(self, original_str):
        stack = []
        for c in original_str:
            if c == '#':
                if len(stack)>0: stack.pop()
            else:
                stack.append(c)
        return stack

    def backspaceCompare(self, S: str, T: str) -> bool:
        S_stack = self.typed_str_stack(S)
        T_stack = self.typed_str_stack(T)
        if len(S_stack) != len(T_stack): return False
        for c_s, c_t in zip(S_stack, T_stack):
            if c_s != c_t:
                return False
        return True
