"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        def subImportance(cur_id):
            total = 0
            for e in employees:
                if e.id == cur_id:
                    total += e.importance
                    for sub in e.subordinates:
                        total += subImportance(sub)
            return total

        return subImportance(id)
