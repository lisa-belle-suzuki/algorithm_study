class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        idx_map = defaultdict(list)
        for i,num in enumerate(B):
            idx_map[num].append(i)

        ans = []
        for num in A:
            idx = idx_map[num].pop()
            ans.append(idx)
        return ans
