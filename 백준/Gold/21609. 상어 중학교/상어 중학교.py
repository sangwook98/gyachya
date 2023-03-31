import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
answer = 0


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def bfs():
    global answer
    visited = [[False]*n for _ in range(n)]
    maxi = [[], []]
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and graph[i][j] > 0:
                visited[i][j] = True
                q = [(i, j)]
                begin = 0
                stack = [[(i, j)], []]
                while len(q) > begin:
                    x, y = q[begin]
                    begin += 1

                    for k in range(4):
                        nx = x + dx[k]
                        ny = y + dy[k]
                        if is_valid(nx, ny) and not visited[nx][ny] and (graph[nx][ny] == 0 or graph[nx][ny] == graph[i][j]):
                            visited[nx][ny] = True
                            if graph[nx][ny] == 0:
                                stack[1].append((nx, ny))
                            else:
                                stack[0].append((nx, ny))
                            q.append((nx, ny))

                a, b, c, d = len(maxi[0]), len(
                    maxi[1]), len(stack[0]), len(stack[1])

                if c+d >= 2:
                    if c+d > a+b or (c+d == a+b and d >= b):
                        maxi[0] = stack[0][:]
                        maxi[1] = stack[1][:]

                for a, b in stack[1]:
                    visited[a][b] = False

    # 제거
    if maxi[0]:
        for x, y in maxi[0]:
            graph[x][y] = -2
        for x, y in maxi[1]:
            graph[x][y] = -2

        answer += (len(maxi[0])+len(maxi[1]))**2

        return True
    else:
        return False


def gravity():
    for y in range(n):
        q = []
        begin = 0
        for x in range(n-1, -1, -1):
            if graph[x][y] == -1:
                q.clear()
                begin = 0
            elif graph[x][y] >= 0:
                if q:
                    a, b = q[begin]
                    begin += 1
                    graph[a][b] = graph[x][y]
                    graph[x][y] = -2
                    q.append((x, y))
            elif graph[x][y] == -2:
                q.append((x, y))


def counter_clock():
    temp = [[-2]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            temp[n-j-1][i] = graph[i][j]

    for i in range(n):
        graph[i] = temp[i][:]


def pp(comment=''):
    print(comment)
    for i in graph:
        print(i, sep='')
    print('answer', answer)
    print('-')


# 크기 가장 큰 블록 찾기, 제거
while bfs():
    # 중력
    # pp('bfs')
    gravity()
    # pp('gravity')
    # 반시계회전
    counter_clock()

    # pp('counter')
    # 중력
    gravity()
    # pp('gravity')
print(answer)
