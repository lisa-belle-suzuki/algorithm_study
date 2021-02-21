class LargerInt(int):
    def __lt__(x, y):
        cnt_x = bin(x).count('1')
        cnt_y = bin(y).count('1')
        if cnt_x==cnt_y:
            return x > y
        else:
            return cnt_x > cnt_y

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=LargerInt, reverse=True)
