num = int(input())

for i in range(num):
    a, b = map(int, input().split())
    cash = list(map(int, input().split()))

    anstable = [0] * (b + 1)

    for j in range(b):  #j = 0 to b-1
        tmpmin = b
        for k in range(0, a, 1):  #k = cash[0] to cash[a - 1]
            if j + 1 - cash[k] < 0:
                break
            tmpnum = anstable[j + 1 - cash[k]] + 1
            if tmpnum < tmpmin:
                tmpmin = tmpnum
        anstable[j + 1] = tmpmin
    print(anstable[b])