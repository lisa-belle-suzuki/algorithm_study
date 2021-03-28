class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1])
        ret = 0
        while boxTypes:
            cur = boxTypes.pop()
            if truckSize >= cur[0]:
                ret += cur[0] * cur[1]
                truckSize -= cur[0]
            else:
                ret += truckSize * cur[1]
                break
        return ret
