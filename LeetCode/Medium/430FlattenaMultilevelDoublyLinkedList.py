"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        stack = []
        new_head = None
        stack.append(head)
        prev = None
        while stack:
            cur = stack.pop()
            new_cur = Node(None, prev, None, None)
            if prev:
                prev.next = new_cur
            if cur is None:
                continue
            new_cur.val = cur.val
            if cur == head:
                new_head = new_cur

            n = cur.next
            c = cur.child
            if n:
                stack.append(n)
            if c:
                stack.append(c)

            prev = new_cur

        return new_head
