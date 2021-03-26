class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ret = []
        edges = {}

        def write_edge(dividend, divisor, val):
            if dividend in edges:
                if divisor not in edges[dividend]:
                    edges[dividend][divisor] = val
            else:
                edges[dividend] = {}
                edges[dividend][divisor] = val
            return

        for eq, val in zip(equations, values):
            write_edge(eq[0], eq[1], val)
            write_edge(eq[1], eq[0], 1/val)

        def is_found(tgt):
            return tgt in edges

        def calc(dividend, divisor):
            stack = [[dividend, 1]]
            visited = set()
            while stack:
                variable, ans = stack.pop()
                if variable in visited:
                    continue
                if variable == divisor:
                    return ans
                for node in edges[variable].keys():
                    val = edges[variable][node]
                    stack.append([node, ans * val])
                visited.add(variable)
            return -1.0

        ret = []
        for q in queries:
            dividend, divisor = q
            if not is_found(dividend) or not is_found(divisor):
                ret.append(-1.0)
                continue
            if dividend == divisor:
                ret.append(1.0)
                continue
            ret.append(calc(dividend, divisor))

        return ret
