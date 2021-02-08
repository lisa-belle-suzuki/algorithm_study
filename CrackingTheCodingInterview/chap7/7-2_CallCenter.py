from collections import deque
from enum import Enum

class EmployeePos(Enum):
    OPR = 'operator'
    MGR = 'manager'
    DIR = 'director'


class CallCenter:
    def __init__(self, employees):
        self.employees = {}
        for e in employees:
            if e.pos.value not in self.employees:
                q = deque()
                q.append(e)
                self.employees[e.pos.value] = q
            else:
                self.employees[e.pos.value].append(e)

    def dispatch_call(self):
        for pos in EmployeePos:
            if len(self.employees[pos.value]) > 0:
                return self.employees[pos.value].popleft()
        return None

    def push_back_employee(self, e):
        if e.pos.value not in self.employees:
            q = deque()
            q.append(e)
            self.employees[e.pos.value] = q
        else:
            self.employees[e.pos.value].append(e)
        return


class Employee:
    def __init__(self, name, pos: EmployeePos):
        self.name = name
        self.pos = pos

    def report_back(self, center: CallCenter):
        center.push_back_employee(self)
        print(self.name, "came back!")
        return


class Caller:
    def call(self, center: CallCenter):
        answerer = center.dispatch_call()
        if answerer is None:
            print("no answerer available")
            return None
        print("answerer = ", answerer.name, answerer.pos.value)
        return


if __name__=='__main__':
    employee_list = [
        Employee('yamada', EmployeePos.OPR),
        Employee('yamada2', EmployeePos.OPR),
        Employee('yamada3', EmployeePos.OPR),
        Employee('takahashi', EmployeePos.MGR),
        Employee('takahashi2', EmployeePos.MGR),
        Employee('suzuki', EmployeePos.DIR),
        Employee('suzuki2', EmployeePos.DIR)
        ]
    center = CallCenter(employee_list)
    caller = Caller()

    # 呼び出し
    for _ in range(8):
        caller.call(center)
    employee_list[1].report_back(center)
    import pdb;pdb.set_trace()