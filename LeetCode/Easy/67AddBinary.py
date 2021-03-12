class Solution:
    def addBinary(self, a: str, b: str) -> str:
        def addBinaryLargeSmall(l: str, s: str):
            ret = ""
            l = l[::-1]
            s = s[::-1]
            carry = 0
            for i in range(len(s)):
                l_bit = l[i]
                s_bit = s[i]
                if l_bit == '1':
                    if s_bit == '1':
                        if carry == 1:
                            ret += "1"
                            carry = 1
                        else:
                            ret += "0"
                            carry = 1
                    else:
                        if carry == 1:
                            ret += "0"
                            carry = 1
                        else:
                            ret += "1"
                            carry = 0
                else:
                    if s_bit == '1':
                        if carry == 1:
                            ret += "0"
                            carry = 1
                        else:
                            ret += "1"
                            carry = 0
                    else:
                        if carry == 1:
                            ret += "1"
                            carry = 0
                        else:
                            ret += "0"
                            carry = 0
            for i in range(len(s), len(l)):
                if carry == 1:
                    if l[i] == '1':
                        ret += "0"
                    else:
                        ret += "1"
                        carry = 0
                else:
                    if l[i] == '1':
                        ret += "1"
                        carry = 0
                    else:
                        ret += "0"
            if carry == 1:
                ret += "1"
            return ret[::-1]

        if len(a) > len(b):
            return addBinaryLargeSmall(a, b)
        else:
            return addBinaryLargeSmall(b, a)
