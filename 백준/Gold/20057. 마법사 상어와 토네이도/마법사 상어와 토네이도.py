import sys
input = sys.stdin.readline
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]
x, y, dir = n//2, n//2, 6
answer = 0


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def sand_move(x, y, dir):
    global answer
    total = graph[x][y]
    for percent, s, d in (0.1, 1, 1), (0.07, 2, 1), (0.01, 3, 1), (0.02, 2, 2), (0.05, 0, 2):
        value = int(total*percent)
        for i in 1, -1:
            dirr = (dir+i*s) % 8
            nx = x + dx[dirr]*d
            ny = y + dy[dirr]*d
            if is_valid(nx, ny):
                graph[nx][ny] += value
            else:
                answer += value
            graph[x][y] -= value

            if percent == 0.05:
                break

    # 알파 보내기
    nx = x + dx[dir]
    ny = y + dy[dir]
    if is_valid(nx, ny):
        graph[nx][ny] += graph[x][y]
    else:
        answer += graph[x][y]
    graph[x][y] = 0


for i in range(1, n+1):
    for j in range(2):
        for k in range(1, i+1):

            x += dx[dir]
            y += dy[dir]
            if graph[x][y]:
                sand_move(x, y, dir)

        dir = (dir-2) % 8

        if i == n:
            break
    # print(graph, answer)
print(answer)
