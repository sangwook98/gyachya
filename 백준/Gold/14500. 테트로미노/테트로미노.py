import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

horizon_2_graph = [i[:] for i in graph]
for i in range(n):
    for j in range(1, m):
        horizon_2_graph[i][j] += graph[i][j-1]

vertical_2_graph = [i[:] for i in graph]
for i in range(1, n):
    for j in range(m):
        vertical_2_graph[i][j] += graph[i-1][j]

horizon_3_graph = [i[:] for i in graph]
for i in range(n):
    for j in range(2, m):
        horizon_3_graph[i][j] += horizon_2_graph[i][j-1]

vertical_3_graph = [i[:] for i in graph]
for i in range(2, n):
    for j in range(m):
        vertical_3_graph[i][j] += vertical_2_graph[i-1][j]

horizon = [(0, 2), (1, -1), (1, 1), (1, 0)]
vertical = [(2, 0), (1, 1), (1, -1)]

horizon_3 = [(1, -2), (1, -1), (1, 0), (-1, -2), (-1, -1), (-1, 0)]
vertical_3 = [(-2, 1), (-1, 1), (0, 1), (-2, -1), (-1, -1), (0, -1)]

answer = 0


def horizon_is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= m-1 and 0 <= ny-1 < m-1


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= m-1


for x in range(n):
    for y in range(1, m):
        for dx, dy in horizon:
            nx = x + dx
            ny = y + dy
            if horizon_is_valid(nx, ny):
                answer = max(
                    answer, horizon_2_graph[x][y]+horizon_2_graph[nx][ny])

for x in range(1, n):
    for y in range(m):
        for dx, dy in vertical:
            nx = x + dx
            ny = y + dy
            if is_valid(nx, ny):
                answer = max(
                    answer, vertical_2_graph[x][y] + vertical_2_graph[nx][ny])

for x in range(n):
    for y in range(2, m):
        for dx, dy in horizon_3:
            nx = x + dx
            ny = y + dy
            if is_valid(nx, ny):
                answer = max(
                    answer, horizon_3_graph[x][y]+graph[nx][ny])

for x in range(2, n):
    for y in range(m):
        for dx, dy in vertical_3:
            nx = x + dx
            ny = y + dy
            if is_valid(nx, ny):
                answer = max(
                    answer, vertical_3_graph[x][y] + graph[nx][ny])
print(answer)
