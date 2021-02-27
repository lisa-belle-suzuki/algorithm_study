class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0: return "0"
        minus = ""
        if numerator < 0 and denominator > 0: minus += "-"; numerator *= -1
        elif numerator < 0 and denominator < 0: numerator *= -1; denominator *= -1
        elif numerator > 0 and denominator < 0: minus += "-"; denominator *= -1

        intQ = numerator // denominator
        decimalQ = numerator - denominator * intQ
        if decimalQ == 0: return minus + str(intQ)
        if intQ == 0: ans_str = "0."
        else: ans_str = str(intQ) + "."

        rest_map = {}
        i = len(ans_str)
        while decimalQ > 0:
            if decimalQ in rest_map:
                repeat_start = rest_map[r]
                return minus + ans_str[:repeat_start]\
                        + '(' + ans_str[repeat_start:i] + ')'
            else: rest_map[decimalQ] = i
            decimalQ *= 10
            if decimalQ > denominator:
                q = decimalQ // denominator
                r = decimalQ % denominator
                ans_str += str(q)
                decimalQ = r
            else: ans_str += '0'
            i += 1
        return minus + ans_str
