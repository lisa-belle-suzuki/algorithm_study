# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def isSameTree(tree1, tree2):
            if not tree1 and not tree2:
                return True
            if tree1 and not tree2:
                return False
            if not tree1 and tree2:
                return False

            if tree1.val != tree2.val:
                return False
            return isSameTree(tree1.left, tree2.left) and isSameTree(tree1.right, tree2.right)

        stack = [s]
        while stack:
            cur = stack.pop()
            if cur is None:
                continue
            if isSameTree(cur, t):
                return True
            stack.append(cur.left)
            stack.append(cur.right)
        return False
