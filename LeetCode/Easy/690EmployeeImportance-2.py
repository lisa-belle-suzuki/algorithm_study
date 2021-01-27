"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
from collections import deque
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        q = deque()

        id_to_emp = {}
        for e in employees:
            id_to_emp[e.id] = e

        q.append(id_to_emp[id])
        total = 0
        while q:
            cur = q.popleft()
            total += cur.importance
            for sub_id in cur.subordinates:
                q.append(id_to_emp[sub_id])
        return total
