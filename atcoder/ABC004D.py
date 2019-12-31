# coding: utf-8

R = 267
G = 294 # -147,146
B = 165

g_cnt = 0
for i in range(-147,147):
    # print(i)
    g_cnt += abs(i)

b_cnt = 0
for i in range(147,147+B):
    b_cnt += (i - 100)

r_cnt = 0
for i in range(-147 - R, -147):
    r_cnt += (-100 - i)

print(r_cnt + g_cnt + b_cnt)