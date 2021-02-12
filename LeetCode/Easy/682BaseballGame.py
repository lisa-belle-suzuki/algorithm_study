class Solution:
    def calPoints(self, ops: List[str]) -> int:
        scores = []
        for op in ops:
            if op == 'C':
                scores.pop()
            elif op == 'D':
                prev = scores[-1]
                cur = prev * 2
                scores.append(cur)
            elif op == '+':
                cur = scores[-1] + scores[-2]
                scores.append(cur)
            else:
                scores.append(int(op))
        return sum(scores)
