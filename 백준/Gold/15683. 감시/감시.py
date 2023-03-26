import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
pos = []
zeros = 0
answer = 100

for i in range(n):
    for j in range(m):
        if 6 > graph[i][j] > 0:
            pos.append((i, j))
        elif graph[i][j] == 0:
            zeros += 1

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= m-1


def beam(x, y, dir):
    cnt = []
    while True:
        x += dx[dir]
        y += dy[dir]
        if is_valid(x, y):
            if graph[x][y] == 0:
                cnt.append((x, y))
            elif graph[x][y] == 6:
                break
        else:
            break
    return cnt


def dfs(cnt, index):
    global answer
    # dfs 탈출조건
    if index == len(pos) or cnt == 0:
        answer = min(answer, cnt)
        if answer == 0:
            print(0)
            sys.exit()
        # print(answer)
        # print(graph)
        return

    x, y = pos[index]
    # cctv 번호에 맞는 for 문
    if graph[x][y] == 1:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if is_valid(nx, ny):
                c = beam(x, y, i)
                for a, b in c:
                    graph[a][b] = "#"
                dfs(cnt-len(c), index + 1)
                for a, b in c:
                    graph[a][b] = 0

    if graph[x][y] == 2:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if is_valid(nx, ny):
                c = beam(x, y, i)
                cc = beam(x, y, (i+2) % 4)
                for a, b in c:
                    graph[a][b] = "#"
                for a, b in cc:
                    graph[a][b] = "#"
                dfs(cnt-len(c)-len(cc), index + 1)
                for a, b in c:
                    graph[a][b] = 0
                for a, b in cc:
                    graph[a][b] = 0
    if graph[x][y] == 3:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if is_valid(nx, ny):
                c = beam(x, y, i)
                cc = beam(x, y, (i+1) % 4)
                for a, b in c:
                    graph[a][b] = "#"
                for a, b in cc:
                    graph[a][b] = "#"
                dfs(cnt-len(c)-len(cc), index + 1)
                for a, b in c:
                    graph[a][b] = 0
                for a, b in cc:
                    graph[a][b] = 0
    if graph[x][y] == 4:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if is_valid(nx, ny):
                c = beam(x, y, i)
                cc = beam(x, y, (i+1) % 4)
                ccc = beam(x, y, (i-1) % 4)
                for a, b in c:
                    graph[a][b] = "#"
                for a, b in cc:
                    graph[a][b] = "#"
                for a, b in ccc:
                    graph[a][b] = "#"
                dfs(cnt-len(c)-len(cc)-len(ccc), index + 1)
                for a, b in c:
                    graph[a][b] = 0
                for a, b in cc:
                    graph[a][b] = 0
                for a, b in ccc:
                    graph[a][b] = 0
    if graph[x][y] == 5:
        c = beam(x, y, 0)
        cc = beam(x, y, (0+1) % 4)
        ccc = beam(x, y, (0+2) % 4)
        cccc = beam(x, y, (0+3) % 4)
        for a, b in c:
            graph[a][b] = "#"
        for a, b in cc:
            graph[a][b] = "#"
        for a, b in ccc:
            graph[a][b] = "#"
        for a, b in cccc:
            graph[a][b] = "#"
        dfs(cnt-len(c)-len(cc)-len(ccc)-len(cccc), index + 1)
        for a, b in c:
            graph[a][b] = 0
        for a, b in cc:
            graph[a][b] = 0
        for a, b in ccc:
            graph[a][b] = 0
        for a, b in cccc:
            graph[a][b] = 0


dfs(zeros, 0)
print(answer)
