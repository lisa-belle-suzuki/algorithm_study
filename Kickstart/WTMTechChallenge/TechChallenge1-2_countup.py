N = 1000
sum = 0
for i in range(1,N+1):
    if i%15==0:
        sum += (i*10)
    elif i%3==0:
        sum += (i*2)
    elif i%5==0:
        sum += (i*3)

    else:
        sum += i
    # print(sum)
print(sum)