class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        cnt = defaultdict(int)
        N = len(A)//2
        for num in A:
            cnt[num] += 1
            if cnt[num] == N:
                return num
        return -1
