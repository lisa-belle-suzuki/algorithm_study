import heapq


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        count = defaultdict(int)
        for w in words:
            count[w] += 1

        count2words = defaultdict(list)
        sorted_count = []
        for key in count.keys():
            cnt = count[key]
            count2words[cnt].append(key)
            heapq.heappush(sorted_count, -cnt)

        i = 0
        ret = []
        prev_cnt = float('inf')
        while i < k and sorted_count:
            cnt = -heapq.heappop(sorted_count)
            if prev_cnt == cnt:
                continue
            words = count2words[cnt]
            if i + len(words) < k:
                ret.extend(sorted(words))
                i += len(words)
            else:
                ret.extend(sorted(words)[:k-i])
                i = k
            prev_cnt = cnt
        return ret
