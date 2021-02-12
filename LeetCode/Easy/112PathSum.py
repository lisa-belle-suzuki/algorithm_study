# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if root is None: return False

        sums = []
        def calc_sum_of_family(cur_node, cur_sum):
            new_sum = cur_sum + cur_node.val
            if not cur_node.left and not cur_node.right: sums.append(new_sum)
            if cur_node.left: calc_sum_of_family(cur_node.left, new_sum)
            if cur_node.right: calc_sum_of_family(cur_node.right, new_sum)
            return

        calc_sum_of_family(root, 0)
        print("sums=", sums)
        for s in sums:
            if s==targetSum:
                return True
        return False
