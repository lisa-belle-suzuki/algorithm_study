# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.path_sum_map = {}
        self.max = -1001 * 30000

    def max_in_nums(self, nums):
        cur_max = -float('inf')
        for num in nums:
            if num > cur_max:
                cur_max = num
        return cur_max

    def maxPathSum(self, root: TreeNode) -> int:
        # curの値を含む最大のpath sum
        def max_path_sum(cur):
            if cur is None: return None
            if id(cur) in self.path_sum_map:
                return self.path_sum_map[id(cur)]
            left = cur.left
            right = cur.right

            left_max = max_path_sum(left)
            right_max = max_path_sum(right)

            if left_max and right_max:
                cur_left_right = cur.val + left_max + right_max
                cur_max = self.max_in_nums([
                    cur.val,
                    cur.val + left_max,
                    cur.val + right_max
                ])
                if cur_left_right > cur_max:
                    if cur_left_right > self.max:
                        self.max = cur_left_right
                self.path_sum_map[id(cur)] = cur_max
                if cur_max > self.max: self.max = cur_max
                return cur_max
            elif not left_max and not right_max:
                cur_max = cur.val
            elif not left_max and right_max:
                cur_max = self.max_in_nums([
                    cur.val,
                    cur.val + right_max
                ])
            elif left_max and not right_max:
                cur_max = self.max_in_nums([
                    cur.val,
                    cur.val + left_max
                ])
            self.max = max(self.max, cur_max)
            self.path_sum_map[id(cur)] = cur_max
            return cur_max

        root_max = max_path_sum(root)
        return self.max
