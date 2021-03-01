# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        if root is None: return None

        def dfs(cur):
            if cur is None: return []
            return dfs(cur.left) + [cur] + dfs(cur.right)

        # dfs
        nums = dfs(root)

        # binary search
        idx = -1
        l = 0
        r = len(nums)-1
        while l <= r:
            if l<0 or r>=len(nums): continue
            c = (l+r)//2
            if nums[c].val==p.val: idx = c; break
            elif nums[c].val > p.val: r = c-1
            elif nums[c].val < p.val: l = c+1

        if idx == len(nums)-1: return None
        else: return nums[idx+1]
