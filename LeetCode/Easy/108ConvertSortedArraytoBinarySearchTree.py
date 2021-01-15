# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def subSortedArrayToBST(nums: List[int]):
    # n//2番目の要素をrootに
    # それより前の要素を左側のsubtreeに
    # それより後の要素を右側のsubtreeに
    # 終了条件: リストが空
    if len(nums) == 0:
        return None
    elif len(nums) == 1:
        return TreeNode(val=nums[0])
    else:
        center_idx = len(nums) // 2
        root_node = TreeNode(val=nums[center_idx])
        root_node.left = subSortedArrayToBST(nums[:center_idx])
        root_node.right = subSortedArrayToBST(nums[center_idx+1:])
        return root_node

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        # if len(nums) == 0:
        #     return TreeNode(None)
        # elif len(nums) == 1:
        #     return TreeNode(nums[0])
        # else:
        #     center_idx = len(nums) // 2
        #     root_node = TreeNode(val=nums[center_idx])
        #     root_node.left = subSortedArrayToBST(nums[:center_idx])
        #     root_node.right = subSortedArrayToBST(nums[center_idx+1:])
        #     return root_node
        return subSortedArrayToBST(nums)
        