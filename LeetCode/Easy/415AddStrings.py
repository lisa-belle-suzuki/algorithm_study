class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        char_to_num = {
            "0": 0,
            "1": 1,
            "2": 2,
            "3": 3,
            "4": 4,
            "5": 5,
            "6": 6,
            "7": 7,
            "8": 8,
            "9": 9
        }

        def calc(num1, num2):
            ret = ""
            carry = 0
            for c1, c2 in zip(num1[::-1], num2[::-1]):
                num = char_to_num[c1] + char_to_num[c2] + carry
                if num >= 10:
                    num -= 10
                    carry = 1
                else:
                    carry = 0
                ret += str(num)
            if len(num1) > len(num2):
                rest = num1[::-1][len(num2):]
                for c in rest:
                    num = char_to_num[c] + carry
                    if num >= 10:
                        num -= 10
                        carry = 1
                    else:
                        carry = 0
                    ret += str(num)
            if carry == 1:
                ret += "1"
            return ret[::-1]

        if len(num1) > len(num2):
            return calc(num1, num2)
        else:
            return calc(num2, num1)
