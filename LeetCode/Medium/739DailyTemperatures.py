class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        ans = [0] * len(T)
        for idx,temp in enumerate(T):
            while len(stack)>0:
                top_idx, top_temp = stack[-1]
                if top_temp >= temp: break
                top_idx, top_temp = stack.pop()
                ans[top_idx] = idx - top_idx
            stack.append((idx, temp))

        return ans
