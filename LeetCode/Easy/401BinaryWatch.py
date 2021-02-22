from collections import deque

def bit_str_to_int(bit_str):
    power_of_two = 1
    ret = 0
    for c in bit_str[::-1]:
        if c == '1': ret += power_of_two
        power_of_two *= 2
    return ret

def replace_zero_by_one_list(length: int, replace_nums: int):
    q = deque()
    q.append("")
    ret = []
    while q:
        cur = q.popleft()
        if cur.count('1') > replace_nums: continue
        if len(cur)==length:
            if cur.count('1')==replace_nums:
                ret.append(cur)
            continue
        q.append(cur + '0')
        q.append(cur + '1')
    return [bit_str_to_int(bit_str) for bit_str in ret]


def time_str(hour_int: int, min_int: int) -> str:
    if min_int < 10:
        return str(hour_int) + ':0' + str(min_int)
    else:
        return str(hour_int) + ':' + str(min_int)

class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        if num==0: return ['0:00']

        ans = []
        for hour_replace in range(num+1):
            minute_replace = num - hour_replace
            hour_int_list = replace_zero_by_one_list(4, hour_replace)
            min_int_list = replace_zero_by_one_list(6, minute_replace)
            for hour_int in hour_int_list:
                for min_int in min_int_list:
                    if hour_int > 11 or min_int > 59: continue
                    ans.append(time_str(hour_int, min_int))
        return ans
