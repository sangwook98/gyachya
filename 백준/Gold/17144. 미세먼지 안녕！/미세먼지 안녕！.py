import sys
input = sys.stdin.readline
r, c, t = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(r)]


def find():
    for i in range(r):
        if graph[i][0] == -1:
            return (i, 0), (i+1, 0)


clean1, clean2 = find()

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def is_valid(nx, ny):
    return 0 <= nx <= r-1 and 0 <= ny <= c-1


def up_move(new_graph):
    x, y, dir = clean1[0], 1, 1
    previous = 0
    while True:
        nx = x + dx[dir]
        ny = y + dy[dir]
        if x == clean1[0] and y == 0:
            break

        if not is_valid(nx, ny):
            dir = (dir-1) % 4
            continue

        new_graph[x][y], previous = previous, new_graph[x][y]
        x, y = nx, ny


def down_move(new_graph):
    x, y, dir = clean2[0], 1, 1
    previous = 0
    while True:
        nx = x + dx[dir]
        ny = y + dy[dir]
        if x == clean2[0] and y == 0:
            break

        if not is_valid(nx, ny):
            dir = (dir+1) % 4
            continue

        new_graph[x][y], previous = previous, new_graph[x][y]
        x, y = nx, ny


for _ in range(t):
    new_graph = [[0]*c for _ in range(r)]
    for x in range(r):
        for y in range(c):
            if 5 > graph[x][y]:
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
    up_move(new_graph)
    down_move(new_graph)
    graph = new_graph

ans = 0
for i in graph:
    ans += sum(i)
print(ans+2)
