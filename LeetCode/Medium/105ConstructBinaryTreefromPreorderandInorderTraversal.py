# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None

        # init
        pre_idx = 0; in_idx = 0
        root = TreeNode()
        num_to_node = {}
        cur = root
        while pre_idx < len(preorder) and in_idx < len(inorder):
            # 現在のノード確定
            num = preorder[pre_idx]
            cur.val = num
            num_to_node[num] = cur
            if num != inorder[in_idx]:
                pre_idx += 1
                # inと一致するまで左に伸ばす
                if pre_idx >= len(preorder) or in_idx >= len(inorder):
                    break
                while preorder[pre_idx] != inorder[in_idx]:
                    num = preorder[pre_idx]
                    left = TreeNode(num)
                    num_to_node[num] = left
                    cur.left = left
                    cur = left
                    pre_idx += 1
                num = preorder[pre_idx]
                left = TreeNode(num)
                num_to_node[num] = left
                cur.left = left
                cur = left
            # 一致したら，inをunvisitedになる手前まで進める
            in_idx_prev = in_idx
            while 1: # while visited
                if in_idx not in range(len(inorder)):
                    return root
                if inorder[in_idx] in num_to_node:
                    in_idx += 1
                else:
                    break
            if in_idx != in_idx_prev:
                in_idx -= 1

            # そのノードの右につけるのは，pre[idx+1]の値
            cur = num_to_node[inorder[in_idx]]
            pre_idx += 1
            in_idx += 1
            if pre_idx not in range(len(preorder)) or in_idx not in range(len(inorder)):
                break
            cur.right = TreeNode()
            cur = cur.right

        return root
