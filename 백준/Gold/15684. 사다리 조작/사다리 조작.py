from itertools import combinations
n, m, h = map(int, input().split())

graph = [[0]*n for _ in range(h)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[a-1][b] = -1

answer = 4


def check():
    for i in range(n):
        y = i
        for x in range(h):
            if graph[x][y] == 1:
                y += 1
            elif graph[x][y] == -1:
                y -= 1

        if y != i:
            return False
    return True


candidate = []
for x in range(h):
    for y in range(n-1):
        if graph[x][y] == 0 and graph[x][y+1] == 0:
            candidate.append((x, y))

cnt = False
for i in range(4):
    for seq in combinations(candidate, i):
        for x, y in seq:
            graph[x][y] = 1
            graph[x][y+1] = -1

        if check():
            answer = i
            cnt = True
            break

        for x, y in seq:
            graph[x][y] = 0
            graph[x][y+1] = 0

    if cnt:
        break


print(-1 if answer > 3 else answer)
