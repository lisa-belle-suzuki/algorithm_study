class Solution:
    def numberOfSteps (self, num: int) -> int:
        if num==0: return 0
        steps = 0
        power_of_two = 1
        while power_of_two <= num:
            if (power_of_two & num)==0:
                # 0 (桁が上がるだけ)
                steps += 1
            else:
                # 1 (マイナス1をする上に，桁が上がる)
                steps += 2
            power_of_two <<= 1
        return steps - 1
