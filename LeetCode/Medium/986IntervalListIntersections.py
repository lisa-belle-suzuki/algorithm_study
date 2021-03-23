class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = 0
        j = 0
        ret = []
        while i < len(firstList) and j < len(secondList):
            l, r = firstList[i]
            L, R = secondList[j]
            if l < L:
                if r == L:
                    ret.append([r, r])
                    i += 1
                elif r > L:
                    if R <= r:
                        ret.append([L, R])
                        j += 1
                    else:  # R > r
                        ret.append([L, r])
                        i += 1
                else:
                    i += 1
            elif l == L:
                if R == r:
                    ret.append([l, r])
                    i += 1
                    j += 1
                elif R < r:
                    ret.append([l, R])
                    j += 1
                else:  # R > r
                    ret.append([l, r])
                    i += 1
            else:  # l > L
                if R == l:
                    ret.append([R, R])
                    j += 1
                elif R > l:
                    if r <= R:
                        ret.append([l, r])
                        i += 1
                    else:  # r > R
                        ret.append([l, R])
                        j += 1
                else:
                    j += 1

        return ret
