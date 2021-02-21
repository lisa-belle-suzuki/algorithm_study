class Solution:
    def __init__(self):
        self.isPrime = [True] * 1000001
        self.isPrime[0] = False
        self.isPrime[1] = False
        self.set_prime(20)


    def set_prime(self, upper):
        i = 2
        while i * i <= upper:
            cur = i
            while cur <= upper:
                # print(cur, " is not prime")
                cur += i
                self.isPrime[cur] = False
            i += 1
        return


    def countPrimeSetBits(self, L: int, R: int) -> int:
        cnt = 0
        for i in range(L, R+1):
            # print("i=", i)
            one_cnt = bin(i).count('1')
            # print("one_cnt=", one_cnt)
            if self.isPrime[one_cnt]==True:
                # print("aaaa")
                cnt += 1
        return cnt
