import sys
input = sys.stdin.readline

n = int(input())

liked = [[] for _ in range(n**2 + 1)]
order = []
for _ in range(n**2):
    a, b, c, d, e = list(map(int, input().split()))
    order.append(a)
    liked[a] = [b, c, d, e]


checker = [[4]*n for _ in range(n)]
checker[0][0], checker[0][n-1], checker[n-1][0], checker[n-1][n-1] = 2, 2, 2, 2
for i in 0, n-1:
    for j in range(1, n-1):
        checker[i][j] = 3
        checker[j][i] = 3

graph = [[0]*n for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def rule1(num):
    result = []
    for x in range(n):
        for y in range(n):
            if graph[x][y] == 0:
                tmp = 0
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if is_valid(nx, ny) and graph[nx][ny] in liked[num]:
                        tmp += 1

                res = (tmp, checker[x][y], x, y)
                result.append(res)
    result = sorted(result, key=lambda x: (-x[0], -x[1], x[2], x[3]))

    return result[0][2], result[0][3]


def reduce(x, y):
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if is_valid(nx, ny):
            checker[nx][ny] -= 1


for num in order:
    x, y = rule1(num)
    graph[x][y] = num
    reduce(x, y)


answer = 0
for x in range(n):
    for y in range(n):
        cnt = 0
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx <= n-1 and 0 <= ny <= n-1 and graph[nx][ny] in liked[graph[x][y]]:
                cnt += 1

        a = 0 if cnt == 0 else 10**(cnt-1)
        answer += a
print(answer)
