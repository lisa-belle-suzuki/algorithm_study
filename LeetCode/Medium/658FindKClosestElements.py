import bisect


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        idx = bisect.bisect_left(arr, x)
        count = 0
        ret = []
        l = idx - 1
        r = idx
        if 0 <= idx < len(arr) and arr[idx] == x:
            count += 1
            r += 1
            ret.append(x)
        while count < k:
            if l < 0:
                if r >= len(arr):
                    break
                else:
                    ret.append(arr[r])
                    r += 1
            else:
                if r >= len(arr):
                    ret.append(arr[l])
                    l -= 1
                else:
                    if abs(arr[l]-x) <= abs(arr[r]-x):
                        ret.append(arr[l])
                        l -= 1
                    else:
                        ret.append(arr[r])
                        r += 1
            count += 1
        return sorted(ret)
