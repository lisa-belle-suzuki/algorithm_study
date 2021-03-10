class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        N = len(nums)
        nums.sort()
        # 2つの数字を選んで，その和を求める
        # あと1つ選んで0にするには何が必要か考えて，それをにぶたんする

        def search(start_idx, tgt):
            l = start_idx
            r = N-1
            if tgt < nums[start_idx]:
                return -1
            while l <= r:
                if l < start_idx or r >= N:
                    return -1
                c = (l+r)//2
                if nums[c] == tgt:
                    return c
                elif nums[c] < tgt:
                    l = c + 1
                else:
                    r = c - 1
            return -1

        ret = set()
        visited_pairs = set()
        for i in range(N-2):
            for j in range(i+1, N-1):
                two_sum = nums[i] + nums[j]
                if (nums[i], nums[j]) in visited_pairs:
                    continue
                rest = - two_sum
                idx = search(j+1, rest)
                if idx != -1:
                    ret.add((nums[i], nums[j], nums[idx]))
                visited_pairs.add((nums[i], nums[j]))
        return ret
