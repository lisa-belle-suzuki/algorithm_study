from decimal import Decimal

def format_strQ(intQStr: str, decimalStr: str) -> str:
    return intQStr + '.' + recurring_decimal(decimalStr)

def recurring_decimal(decimal: str) -> str:
    # modify decimal
    N = len(decimal)
    if N < 10000: return decimal
    i = 0
    nonZero = 0
    while i < N:
        if decimal[i] != 0:
            nonZero = i
            break

    for i in range(nonZero, N):
        print("i=", i)
        for j in range(i, N):
            repeat = decimal[i:j+1]
            repeat_len = j - i + 1
            isOk = True
            for k in range(8):
                s = j + repeat_len * k     +1
                e = j + repeat_len * (k+1) +1
                if e > N+1:
                    isOk = False
                    break
                if decimal[s:e] != repeat:
                    isOk = False
                    break
            if isOk:
                return decimal[:i] + "(" + repeat + ")"
    return '(' + decimal + ')'

def divide(numerator: int, denominator: int):
    tens = 0
    ans_str = ""
    while True:
        if numerator >= denominator:
            q = numerator // denominator
            ans_str += str(q)
            numerator -= q * denominator
        else:
            ans_str += "0"
        if tens >= 10000: break
        if numerator == 0: break
        tens += 1
        numerator *= 10
    N = len(ans_str)
    intQStr = ans_str[:N-tens]
    decimalStr = ans_str[N-tens:]
    return intQStr, decimalStr

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # treat minus
        if numerator >= 0:
            if denominator > 0: minus = ""
            else: minus = "-"; denominator *= -1
        else:
            if denominator > 0: minus = "-"; numerator *= -1
            else: minus = ""; numerator *= -1; denominator *= -1

        # division
        intQStr, decimalStr = divide(numerator, denominator)
        print("minus=", minus)
        print("intQStr=", intQStr)
        print("decimalStr=", decimalStr)
        print("len of decimalStr = ", len(decimalStr))
        # return ""

        # treat recurring
        if len(decimalStr) == 0:
            print("int only")
            if intQStr == '0': return '0'
            return minus + intQStr
        return minus + format_strQ(intQStr, decimalStr)
