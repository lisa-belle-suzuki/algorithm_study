N = int(input())
ability_list = []
for i in range(N):
    ability = list(map(int, input().split()))
    ability_list.append(ability)

def check(num):
    # 全ての人の能力値を、num以上かどうかで0,1はんてい
    s = set()
    for i in range(N):
        ability = ability_list[i]
        s.add(sum(1 << j for j in range(5) if ability[j] >= num))
    for x in s:
        for y in s:
            for z in s:
                if x | y | z == 31:
                    return True
    return False
    # 任意の3人を選んだ時、11111にできるかどうかをしらべる


# 解でにぶたん
l = 0
r = 1000000002
while l<=r:
    c = (l+r)//2
    if check(c):
        l = c + 1
    else:
        r = c - 1
print(r)