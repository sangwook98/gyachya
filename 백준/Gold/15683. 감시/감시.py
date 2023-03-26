import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
zeros = 0
answer = 100
all_cctv = []

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= m-1


def move(x, y, dir):
    cnt = set()
    for d in dir:
        nx = x
        ny = y
        while True:
            nx += dx[d]
            ny += dy[d]
            if is_valid(nx, ny):
                if graph[nx][ny] == 0:
                    cnt.add((nx, ny))
                elif graph[nx][ny] == 6:
                    break
            else:
                break
    return cnt


for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            zeros += 1
        elif graph[i][j] == 1:
            all_cctv.append([move(i, j, [0]), move(i, j, [1]),
                            move(i, j, [2]), move(i, j, [3])])
        elif graph[i][j] == 2:
            all_cctv.append([move(i, j, [0, 2]), move(i, j, [1, 3])])
        elif graph[i][j] == 3:
            all_cctv.append([move(i, j, [0, 1]), move(
                i, j, [1, 2]), move(i, j, [2, 3]), move(i, j, [3, 0])])
        elif graph[i][j] == 4:
            all_cctv.append([move(i, j, [0, 1, 2]), move(
                i, j, [1, 2, 3]), move(i, j, [2, 3, 0]), move(i, j, [3, 0, 1])])
        elif graph[i][j] == 5:
            all_cctv.append([move(i, j, [0, 1, 2, 3])])


def dfs(index, union):
    global answer
    if index == len(all_cctv):
        answer = min(answer, zeros - len(union))
        return

    for views in all_cctv[index]:
        dfs(index + 1, union | views)


dfs(0, set())
print(answer)
