import sys
from collections import deque
input = sys.stdin.readline

n, m, k = map(int, input().split())
graph = [[deque() for _ in range(n)] for _ in range(n)]
for _ in range(m):
    r, c, m, s, d = map(int, input().split())
    graph[r-1][c-1].append((m, s, d))

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

new_graph = [[deque() for _ in range(n)] for _ in range(n)]
for _ in range(k):
    # 파이어볼 이동
    for x in range(n):
        for y in range(n):
            for i in range(len(graph[x][y])):
                m, s, d = graph[x][y].popleft()
                nx = (x + s*dx[d]) % n
                ny = (y + s*dy[d]) % n
                new_graph[nx][ny].append((m, s, d))

    # 파이어볼 합체
    for x in range(n):
        for y in range(n):
            if len(new_graph[x][y]) == 1:
                graph[x][y].append(new_graph[x][y].popleft())

            elif len(new_graph[x][y]) >= 2:
                mass = 0
                velocity = 0
                dir = set()
                for i in range(len(new_graph[x][y])):
                    m, s, d = new_graph[x][y].popleft()
                    mass += m
                    velocity += s
                    dir.add(d % 2)
                # 파이어볼 4개로 분해
                if mass//5 > 0:
                    if len(dir) == 1:
                        for j in 0, 2, 4, 6:
                            graph[x][y].append((mass//5, velocity//(i+1), j))
                    elif len(dir) == 2:
                        for j in 1, 3, 5, 7:
                            graph[x][y].append((mass//5, velocity//(i+1), j))
    # print(graph)

answer = 0
for x in range(n):
    for y in range(n):
        for i in range(len(graph[x][y])):
            m, _, _ = graph[x][y][i]
            answer += m
print(answer)
