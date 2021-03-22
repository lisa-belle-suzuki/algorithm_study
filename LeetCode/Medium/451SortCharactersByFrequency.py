from collections import defaultdict


class CountList(list):
    def __gt__(self, other):
        return self[1] > other[1]


class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = defaultdict(int)
        for c in s:
            cnt[c] += 1
        cnt_list = []
        for k in cnt.keys():
            cnt_list.append((cnt[k], k))

        cnt_list.sort(reverse=True, key=CountList)

        ret = ""
        for cnt, c in cnt_list:
            ret += c * cnt
        return ret
