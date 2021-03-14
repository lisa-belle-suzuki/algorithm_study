# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def node2num(node):
            ret = 0
            while node:
                ret += node.val
                ret *= 10
                node = node.next
            ret //= 10
            return ret

        def num2node(num):
            num_str = str(num)
            root = ListNode()
            cur = root
            for i, c in enumerate(num_str[:-1]):
                cur.val = int(c)
                cur.next = ListNode()
                cur = cur.next
            cur.val = int(num_str[-1])
            return root

        num1 = node2num(l1)
        num2 = node2num(l2)
        add = num1 + num2
        return num2node(add)
