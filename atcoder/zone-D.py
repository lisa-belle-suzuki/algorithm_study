from collections import deque

def operation(s: str) -> str:
    q = deque()
    rev = False
    for c in s:
        if c == 'R':
            rev = not rev
        elif rev:
            if q and c == q[0]:
                q.popleft()
            else:
                q.appendleft(c)
        else:
            if q and c == q[-1]:
                q.pop()
            else:
                q.append(c)
    if rev:
        q = reversed(q)
    return "".join(q)




if __name__=="__main__":
    S = input()
    print(operation(S))