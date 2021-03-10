import bisect


class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        A.sort()
        B.sort()
        C.sort()
        D.sort()
        N = len(A)
        cnt = 0

        # A,Bで作れるペアを挙げる
        ABsum_to_cnt = defaultdict(int)
        for num1 in A:
            for num2 in B:
                two_sum = num1 + num2
                ABsum_to_cnt[two_sum] += 1
        # C,Dで作れるペアを挙げる
        CDsum_to_cnt = defaultdict(int)
        CDsums = []
        for num1 in C:
            for num2 in D:
                two_sum = num1 + num2
                CDsum_to_cnt[two_sum] += 1
                CDsums.append(two_sum)
        # A,BのペアとC,Dのペアを足し合わせる
        for sum1 in ABsum_to_cnt.keys():
            sum2 = - sum1
            idx = bisect.bisect(CDsums, sum2)
            if idx:
                cnt += ABsum_to_cnt[sum1] * CDsum_to_cnt[sum2]
        return cnt
