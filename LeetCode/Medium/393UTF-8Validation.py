def cnt_first_ones(num: int):
    bitmask = 0b10000000
    cnt = 0
    while bitmask > 0:
        if bitmask & num != 0:
            cnt += 1
        else:
            return cnt
        bitmask >>= 1
    return cnt


class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        N_bytes_length = 0
        is_in_N_bytes = False
        cnt = 0

        for i, num in enumerate(data):
            # Nバイトの途中(先頭が10)
            if is_in_N_bytes:
                if num & 0b11000000 != 0b10000000:
                    return False
                cnt += 1
                # 最後の1文字
                if cnt == N_bytes_length:
                    is_in_N_bytes = False
                continue
            # Nバイトの途中ではない
            ## 先頭が0
            if num & 0b10000000 == 0:
                continue
            ## 先頭が11
            if num & 0b11000000 != 0b11000000:
                return False
            N_bytes_length = cnt_first_ones(num)
            if not (0<=N_bytes_length<=4):
                return False
            is_in_N_bytes = True
            cnt = 1

        if is_in_N_bytes: return False
        return True
