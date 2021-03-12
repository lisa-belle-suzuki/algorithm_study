class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distance_to_point = defaultdict(list)
        distance_list = []

        def square_distance(point):
            return point[0] ** 2 + point[1] ** 2

        for p in points:
            d = square_distance(p)
            distance_to_point[d].append(p)
            distance_list.append(d)

        distance_list.sort()
        ans = []
        i = 0
        while len(ans) < k:
            d = distance_list[i]
            p_list = distance_to_point[d]
            for p in p_list:
                if len(ans) < k:
                    ans.append(p)
            i = len(ans)
        return ans
