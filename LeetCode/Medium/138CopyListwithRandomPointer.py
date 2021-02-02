"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        cur = head
        copy_cur = Node(0)
        head_copy = copy_cur

        originalmem_to_copy_node = {}
        while cur:
            # VAL
            if id(cur) in originalmem_to_copy_node:
                # if 既にoriginalの方がvisitedだったら， originalmem_to_copy_node からそのノードにアクセスし，
                # そこにvalを代入
                copy_cur = originalmem_to_copy_node[id(cur)]
                copy_cur.val = cur.val
            else:
                copy_cur.val = cur.val # 普通にvalを代入
                originalmem_to_copy_node[id(cur)] = copy_cur # visit

            # NEXT
            if id(cur.next) in originalmem_to_copy_node:
                # if 既にoriginalのnextがvisitedだったら， originalmem_to_copy_node からそのノードにアクセスし，
                # それをcopy_cur.nextを代入
                copy_cur.next = originalmem_to_copy_node[id(cur.next)]
            else:
                # nextを用意しておく
                if cur.next is None:
                    copy_cur.next = None
                else:
                    copy_cur.next = Node(0)
                    originalmem_to_copy_node[id(cur.next)] = copy_cur.next

            # RANDOM
            if id(cur.random) in originalmem_to_copy_node:
                # if randomが既にvisitedなら，そのメモリを originalmem_to_copy_node を用いて代入
                copy_cur.random = originalmem_to_copy_node[id(cur.random)]
            else:
                # randomを用意しておく
                if cur.random is None:
                    copy_cur.random = None
                else:
                    copy_cur.random = Node(0)
                    originalmem_to_copy_node[id(cur.random)] = copy_cur.random

            # 進める
            cur = cur.next
            copy_cur = copy_cur.next

        return head_copy
