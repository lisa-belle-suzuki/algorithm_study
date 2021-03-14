class Solution:
    def modifyString(self, s: str) -> str:
        alphabet = [chr(i) for i in range(ord('a'), ord('z')+1)]
        ret = ""
        for i, c in enumerate(s):
            if c == '?':
                if i == 0:
                    if i == len(s)-1:
                        return 'a'  # なんの文字でも良い
                    else:
                        next_c = s[i+1]
                        if next_c == '?':
                            ret += 'a'
                        else:
                            for a in alphabet:
                                if a != next_c:
                                    ret += a
                                    break
                else:
                    if i == len(s)-1:
                        prev_c = ret[i-1]
                        for a in alphabet:
                            if a != prev_c:
                                ret += a
                                break
                    else:
                        prev_c = ret[i-1]
                        next_c = s[i+1]
                        for a in alphabet:
                            if a != prev_c and a != next_c:
                                ret += a
                                break
            else:
                ret += c

        return ret
