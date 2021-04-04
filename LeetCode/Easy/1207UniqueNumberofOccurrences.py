class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = defaultdict(int)
        for num in arr:
            cnt[num] += 1

        cnt_set = set()
        for k in cnt.keys():
            v = cnt[k]
            if v in cnt_set:
                return False
            cnt_set.add(v)
        return True
