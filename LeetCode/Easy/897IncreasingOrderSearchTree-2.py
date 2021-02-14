# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.all_numbers = []
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def traverse(cur):
            if cur is None: return
            self.all_numbers.append(cur.val)
            traverse(cur.left)
            traverse(cur.right)
            return

        traverse(root)
        self.all_numbers.sort(reverse=True)
        new_root = TreeNode(self.all_numbers.pop())
        prev = new_root
        while len(self.all_numbers)>0:
            cur = TreeNode(self.all_numbers.pop())
            prev.right = cur
            prev = cur
        return new_root
