import sys
input = sys.stdin.readline
n, k = map(int, input().split())
belt = [[i, 0] for i in list(map(int, input().split()))]
time = 0
while k > 0:
    time += 1
    # 벨트이동
    a = belt.pop()
    belt.insert(0, a)

    # 로봇내리기
    belt[n-1][1] = 0

    # 로봇이동
    for i in range(n-2, 0, -1):

        if belt[i][1] == 1 and belt[i+1][0] > 0 and belt[i+1][1] == 0:
            belt[i+1][0] -= 1
            if belt[i+1][0] == 0:
                k -= 1

            belt[i][1] = 0
            if i == n-2:
                pass
            else:
                belt[i+1][1] = 1

    # 로봇올리기
    if belt[0][0] > 0:
        belt[0][1] = 1
        belt[0][0] -= 1
        if belt[0][0] == 0:
            k -= 1
print(time)
