"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        depth_to_nodes = defaultdict(list)
        def search(cur, depth):
            if cur is None: return
            depth_to_nodes[depth].append(cur)
            search(cur.left, depth + 1)
            search(cur.right, depth + 1)
            return

        search(root, 0)

        for k,v in depth_to_nodes.items():
            for i,node in enumerate(v[:-1]):
                node.next = v[i+1]
        return root
