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


def dfs(depth, a, b):
    global answer

    if depth >= answer:
        return

    if check():
        answer = min(answer, depth)
        return
    else:
        for x in range(a, h):
            for y in range(b, n-1):
                if graph[x][y] == 0 and graph[x][y+1] == 0:
                    graph[x][y] = 1
                    graph[x][y+1] = -1
                    dfs(depth+1, x, y+2)
                    graph[x][y] = 0
                    graph[x][y+1] = 0
            b = 0


dfs(0, 0, 0)
print(-1 if answer > 3 else answer)
