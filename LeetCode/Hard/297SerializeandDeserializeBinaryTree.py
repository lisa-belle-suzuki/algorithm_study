# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        q = deque()
        q.append(root)
        ret = []
        while q:
            cur = q.popleft()
            if cur is None:
                ret.append("None")
                continue
            ret.append(str(cur.val))
            q.append(cur.left)
            q.append(cur.right)
        i = len(ret)-1
        while i >= 0:
            if ret[i] == "None":
                i -= 1
            else:
                break
        ans = ",".join(ret[:i+1])
        return ans

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        nums = data.split(",")
        if nums[0] == '':
            return None
        root = TreeNode(int(nums[0]))
        children = deque()
        children.append((root, True))
        children.append((root, False))
        i = 1
        while len(children) > 0:
            while len(children) > 0:
                prev, isLeft = children.popleft()
                if i >= len(nums):
                    break
                s = nums[i]
                if s == "None":
                    i += 1
                    continue
                cur = TreeNode(int(s))
                if isLeft:
                    prev.left = cur
                else:
                    prev.right = cur
                children.append((cur, True))
                children.append((cur, False))
                i += 1

        return root


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
