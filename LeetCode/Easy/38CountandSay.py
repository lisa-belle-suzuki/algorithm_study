class Solution:
    def countAndSay(self, n: int) -> str:
        cur_str = "1"
        while n > 1:
            new_str = ""
            # 数えて新しい文字列を作る
            cur_digit = -1
            cnt = 0
            i = 0
            while i < len(cur_str):
                # 同じ文字ならcntを増やす
                if cur_digit == int(cur_str[i]):
                    cnt += 1
                # 違う文字ならそれまでのcntを記録して消し，新たなcntを始める
                else:
                    if cur_digit != -1:
                        new_str += (str(cnt) + str(cur_digit))
                    cur_digit = int(cur_str[i])
                    cnt = 1
                i += 1
            # cur_str, new_strを更新
            if cnt > 0:
                new_str += (str(cnt) + str(cur_digit))
            cur_str = new_str
            n -= 1
        return cur_str
