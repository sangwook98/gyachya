import sys
from collections import deque
input = sys.stdin.readline

m, n, h = map(int, input().split())
graph = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
dx = [-1, 0, 1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

answer = 0
q = deque()
for k in range(h):
    for j in range(n):
        for i in range(m):
            if graph[k][j][i] == 1:
                q.append((i, j, k, 0))

while q:
    x, y, z, time = q.popleft()
    for p in range(6):
        nx = x + dx[p]
        ny = y + dy[p]
        nz = z + dz[p]
        if 0 <= nx <= m-1 and 0 <= ny <= n-1 and 0 <= nz <= h-1 and graph[nz][ny][nx] == 0:
            graph[nz][ny][nx] = 1
            q.append((nx, ny, nz, time+1))
            answer = max(answer, time+1)


def check_zero():
    for k in range(h):
        for j in range(n):
            for i in range(m):
                if graph[k][j][i] == 0:
                    return False
    return True


if check_zero():
    print(answer)
else:
    print(-1)
