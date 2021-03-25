class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        abcost = []
        for c in costs:
            abcost.append([c[0]-c[1], c[0], c[1]])

        abcost.sort(key=lambda x: x[0])

        ret = 0
        for i, c in enumerate(abcost):
            if i < len(abcost)//2:
                ret += c[1]
            else:
                ret += c[2]
        return ret
