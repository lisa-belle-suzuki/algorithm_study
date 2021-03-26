class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        child_map = defaultdict(list)
        root = None
        for process, parent_process in zip(pid, ppid):
            if parent_process == 0:
                root = process
            child_map[parent_process].append(process)

        if root:
            if kill == root:
                return pid

        stack = [kill]
        ret = []
        while len(stack) > 0:
            cur = stack.pop()
            if cur in ret:
                continue
            ret.append(cur)
            if cur not in child_map:
                continue
            children = child_map[cur]
            stack.extend(children)
        return ret
