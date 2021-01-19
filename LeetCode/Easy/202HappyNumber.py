def sum_of_squares_of_digits(n):
    sum_ = 0
    while n // 10 > 0:
        digit = n % 10
        sum_ += (digit ** 2)
        n //= 10
    return sum_ + (n**2)


class Solution:
    def isHappy(self, n: int) -> bool:
        cur_ = n

        isAppearedOnce = {cur_: True}

        while True:
            cur_ = sum_of_squares_of_digits(cur_)

            if cur_ == 1:
                return True

            # 無限ループ判定
            if cur_ in isAppearedOnce:
                return False
            else:
                isAppearedOnce[cur_] = True
