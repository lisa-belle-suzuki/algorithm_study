import bisect


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        N = len(rating)

        def cnt_descending(num_list):
            num_list2 = []
            smaller_list = []
            idx_map = {}

            ret = 0
            for i, num in enumerate(num_list):
                idx_map[num] = i
                insert_idx = bisect.bisect_left(num_list2, num)
                smaller_list.append(num_list2[:insert_idx])
                bisect.insort(num_list2, num)
            for i in range(2, N):
                if len(smaller_list[i]) < 2:
                    continue
                for smaller in smaller_list[i]:
                    ret += len(smaller_list[idx_map[smaller]])
            return ret

        dsc = cnt_descending(rating)
        rating.reverse()
        asc = cnt_descending(rating)

        return asc + dsc
