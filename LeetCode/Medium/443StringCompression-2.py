class Solution:
    def compress(self, chars: List[str]) -> int:
        N = len(chars)
        prev = ''
        count = 0
        write = N-1
        for i in range(N-1, -1, -1):
            c = chars[i]
            if c == prev:
                count += 1
            else:
                if count == 1:
                    # 1文字だけ
                    chars[write] = prev
                    write -= 1
                elif count > 1:
                    # 2文字以上連続
                    while count > 0:
                        chars[write] = str(count % 10)
                        count //= 10
                        write -= 1
                    chars[write] = prev
                    write -= 1
                prev = c
                count = 1

        if count > 1:
            while count > 0:
                chars[write] = str(count % 10)
                count //= 10
                write -= 1
        chars[write] = prev
        write -= 1

        if write != -1:
            chars[::] = chars[write+1:]
            return N - write - 1
        else:
            return N
