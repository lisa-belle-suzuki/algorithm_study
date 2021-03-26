class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        pair_map = {}
        for p in pairs:
            pair_map[p[0]] = p[1]
            pair_map[p[1]] = p[0]

        pref_score = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n-1):
                tgt = preferences[i][j]
                pref_score[i][tgt] = n-1-j

        def isUnhappy(i):
            pair = pair_map[i]
            for j in range(n-1):
                if preferences[i][j] == pair:
                    break
                larger = preferences[i][j]
                pair2 = pair_map[larger]
                if pref_score[larger][i] > pref_score[larger][pair2]:
                    return True
            return False

        cnt = 0
        for i in range(n):
            if isUnhappy(i):
                cnt += 1
        return cnt
