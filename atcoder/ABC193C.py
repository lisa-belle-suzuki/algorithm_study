import math
n = int(input())
rest = set()
for i in range(2, int(math.sqrt(n))+1):
    max_expo = int(math.log(n, i))
    for j in range(2, max_expo+1):
        rest.add(i ** j)

print(n - len(rest))
