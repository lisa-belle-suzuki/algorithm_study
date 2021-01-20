class Solution:
    def countPrimes(self, n: int) -> int:
        isPrime = [True] * 5000001
        isPrime[0] = False
        isPrime[1] = False

        i = 2
        while i ** 2 <= n:
            for j in range(2, (n//i)+1):
                isPrime[j * i] = False
            i += 1

        cnt = 0
        for i in range(1, n):
            if isPrime[i]:
                cnt += 1

        return cnt
