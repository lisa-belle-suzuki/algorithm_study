def num_to_combination(num):
    if num >= 1 and num <= 26:
        return 1
    else:
        return 0

class Solution:
    def numDecodings(self, s: str) -> int:
        memo = {}
        def Decode(s:str) -> int:
            print("s = ", s)
            if s in memo:
                return memo[s]

            if len(s) == 0:
                memo[s] = 1
                return 1

            if len(s) == 1:
                if s == '0':
                    memo[s] = 0
                    return 0
                else:
                    memo[s] = 1
                    return 1

            if s[0] == '0':
                memo[s] = 0
                return 0

            if len(s) == 2:
                if int(s) in range(11, 19+1) or int(s) in range(21, 26+1):
                    memo[s] = 2
                    return 2
                elif int(s) in [10,20,27,28,29]:
                    memo[s] = 1
                    return 1
                elif int(s) % 10 == 0:
                    memo[s] = 0
                    return 0
                else:
                    memo[s] = 1
                    return 1
            else:
                ans1 = num_to_combination(int(s[0])) * Decode(s[1:])
                ans2 = num_to_combination(int(s[:2])) * Decode(s[2:])
                memo[s] = ans1 + ans2
                return ans1 + ans2

        return Decode(s)
