class Solution:
    def compress(self, chars: List[str]) -> int:
        def bits_decimal(num: int) -> int:
            ret = []
            while num > 0:
                ret.append(str(num % 10))
                num //= 10
            return ret[::-1]

        prev = ''
        cnt = 0
        ans = 0
        new_chars = []
        for c in chars:
            if c == prev:
                cnt += 1
            else:
                if cnt == 1:
                    new_chars.append(prev)
                elif cnt > 1:
                    new_chars.append(prev)
                    new_chars.extend(bits_decimal(cnt))
                prev = c
                cnt = 1
        new_chars.append(prev)
        if cnt != 1:
            new_chars.extend(bits_decimal(cnt))
        chars[::] = new_chars[::]
        return len(new_chars)
