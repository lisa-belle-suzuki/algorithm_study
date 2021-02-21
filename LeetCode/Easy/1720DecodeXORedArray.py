class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ret = [first]
        prev = first
        for enc in encoded:
            cur = enc ^ prev
            ret.append(cur)
            prev = cur
        return ret
