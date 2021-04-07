num = int(input())

for i in range(num):
    inputdata, sum = input().split(';')
    inputdata = list(map(int, inputdata.split(' ')))
    sum = int(sum)
    length = len(inputdata)
    sumtable = [[0] * (sum + 1) for j in range(length + 1)]

    for j in range(length):
        for k in range(sum + 1):
            if inputdata[j] <= k:
                sumtable[j + 1][k] = max(sumtable[j][k],
                                  inputdata[j] + sumtable[j][k - inputdata[j]])
            else:
                sumtable[j + 1][k] = sumtable[j][k]
    if sumtable[length][sum] == sum:
        print("True")
    else:
        print("False")