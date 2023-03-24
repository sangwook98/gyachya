import sys
input = sys.stdin.readline

r, c, t = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(r)]


def find():
    for i in range(r):
        for j in range(c):
            if graph[i][j] == -1:
                return (i, j), (i+1, j)


clean1, clean2 = find()

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def is_valid(nx, ny):
    return 0 <= nx <= r-1 and 0 <= ny <= c-1


for _ in range(t):
    new_graph = [[0]*c for _ in range(r)]
    for x in range(r):
        for y in range(c):
            if 5 > graph[x][y] > 0:
                new_graph[x][y] += graph[x][y]
            elif graph[x][y] >= 5:
                mount = graph[x][y]//5
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    if is_valid(nx, ny) and not (nx, ny) == clean1 and not (nx, ny) == clean2:
                        new_graph[nx][ny] += mount
                        graph[x][y] -= mount
                new_graph[x][y] += graph[x][y]

    graph = [[0]*c for _ in range(r)]
    a, d = clean1[0], clean2[0]
    for x in range(r):
        for y in range(c):
            if x <= a:
                if x == 0 and 1 <= y <= c-1:  # 왼쪽으로
                    graph[x][y-1] = new_graph[x][y]
                elif y == 0 and 0 <= x <= a-1:  # 아래로
                    graph[x+1][y] = new_graph[x][y]
                elif x == a and 0 <= y <= c-2:  # 오른쪽으로
                    graph[x][y+1] = new_graph[x][y]
                elif y == c-1 and 1 <= x <= a:  # 위로
                    graph[x-1][y] = new_graph[x][y]
                else:
                    graph[x][y] = new_graph[x][y]

            else:
                if x == r-1 and 1 <= y <= c-1:  # 왼쪽으로
                    graph[x][y-1] = new_graph[x][y]
                elif y == c-1 and d <= x <= r-2:  # 아래로
                    graph[x+1][y] = new_graph[x][y]

                elif x == d and 0 <= y <= c-2:  # 오른쪽으로
                    graph[x][y+1] = new_graph[x][y]
                elif y == 0 and d+1 <= x <= r-1:  # 위로
                    graph[x-1][y] = new_graph[x][y]
                else:
                    graph[x][y] = new_graph[x][y]
    graph[clean1[0]][clean1[1]] = -1
    graph[clean2[0]][clean2[1]] = -1

ans = 0
for i in graph:
    ans += sum(i)
print(ans+2)
