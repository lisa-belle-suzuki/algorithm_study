# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def build(cur):
            if cur is None: return None
            upper = build(cur.left)
            root_node = TreeNode(cur.val)
            lower = build(cur.right)
            if upper is None:
                if lower is None: return root_node
                else:
                    # root and lower
                    root_node.right = lower
                    return root_node
            elif lower is None:
                # root_node and upper
                # find upper's leaf and connect it to root_node
                cur = upper
                while cur.right:
                    if cur.right: cur = cur.right
                upper_leaf = cur
                upper_leaf.right = root_node
                return upper
            else:
                # root_node, upper, and lower
                root_node.right = lower
                # find upper's leaf and connect it to root_node
                cur = upper
                while cur.right:
                    if cur.right: cur = cur.right
                upper_leaf = cur
                upper_leaf.right = root_node
                return upper

        return build(root)
