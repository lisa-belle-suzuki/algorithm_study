def recurrentTrailingZeros(lower: int, upper: int) -> List[int]:
    if lower == upper:
        cnt_five = 0
        cnt_two = 0
        while lower % 5 == 0:
            lower //= 5
            cnt_five += 1
        while lower % 2 == 0:
            lower //= 2
            cnt_two += 1
        return [cnt_five, cnt_two]

    first = recurrentTrailingZeros(lower, (lower + upper)//2)
    cnt_five_first = first[0]
    cnt_two_first = first[1]

    second = recurrentTrailingZeros((lower + upper)//2 + 1, upper)
    cnt_five_second = second[0]
    cnt_two_second = second[1]
    return [cnt_five_first + cnt_five_second, cnt_two_first + cnt_two_second]



class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0:
            return 0

        cnt_five, cnt_two = recurrentTrailingZeros(1,n)
        return min(cnt_five, cnt_two)

