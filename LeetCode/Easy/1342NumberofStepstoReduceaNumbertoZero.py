class Solution:
    def numberOfSteps (self, num: int) -> int:
        cnt = 0
        cur_num = num
        while cur_num>0:
            if cur_num&1==0:
                cur_num>>=1
            else:
                cur_num-=1
            print("cur_num=", cur_num)
            cnt += 1
        return cnt
