class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        thousands = ["", "Thousand", "Million", "Billion"]
        ones = ["Zero", "One", "Two", "Three", "Four",
                "Five", "Six", "Seven", "Eight", "Nine"]
        tens = ["Zero", "Ten", "Twenty", "Thirty", "Forty",
                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        teens = {11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen",
                 15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen"}
        eng_words = []
        i = 0
        while num > 0:
            # 1000毎に3桁ずつ記録していく
            cur = num % 1000
            cur_str = []
            hundred = cur // 100
            cur %= 100
            if hundred > 0:
                cur_str.append(ones[hundred] + " " + "Hundred")

            if cur in teens:
                cur_str.append(teens[cur])
            else:
                ten = cur // 10
                cur %= 10
                one = cur
                if ten > 0:
                    cur_str.append(tens[ten])
                if one > 0:
                    cur_str.append(ones[one])
            if len(cur_str) > 0:
                if i > 0:
                    cur_str.append(thousands[i])
                eng_words.append(" ".join(cur_str))
            num //= 1000
            i += 1
        return " ".join(eng_words[::-1])
