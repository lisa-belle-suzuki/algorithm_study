# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import copy

def reverseLinkedList(node):
    if node is None or node.next is None:
        return node
    p = reverseLinkedList(node.next)
    node.next.next = node
    node.next = None
    return p


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        original_list = copy.deepcopy(head)
        reversed_list = reverseLinkedList(head)

        while original_list is not None:
            if original_list.val != reversed_list.val:
                return False
            original_list = original_list.next
            reversed_list = reversed_list.next

        return True
