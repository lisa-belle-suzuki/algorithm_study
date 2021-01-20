# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def reverseList(node: ListNode):
    if node is None or node.next is None:
        return node
    p = reverseList(node.next)
    # 繋ぐ
    node.next.next = node
    node.next = None
    # 最後に返す
    return p


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        return reverseList(head)
