import sys
input = sys.stdin.readline
n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

change = set()
x, y, dir = n//2, n//2, 3
for i in range(1, n):
    for j in range(2):
        for _ in range(i):
            x += dx[dir]
            y += dy[dir]

        dir = (dir-1) % 4
        change.add((x, y))


def dir_change(d):
    if d == 1:
        return 0
    elif d == 2:
        return 2
    elif d == 3:
        return 3
    elif d == 4:
        return 1


def move(x, y, dir):
    x += dx[dir]
    y += dy[dir]

    if (x, y) in change:
        dir = (dir-1) % 4
    return x, y, dir


def destroy(d, s):
    x, y = n//2, n//2
    for i in range(s):
        x += dx[d]
        y += dy[d]
        if 0 <= x <= n-1 and 0 <= y <= n-1:
            graph[x][y] = 0
        else:
            break


def collect_ball():
    x, y, dir = n//2, n//2, 3
    balls = []
    while True:
        if x == 0 and y == 0:
            break
        x, y, dir = move(x, y, dir)
        if graph[x][y]:
            balls.append(graph[x][y])

    return balls


def get_ball(balls):
    new = [[0]*n for _ in range(n)]
    x, y, dir = n//2, n//2, 3

    for ball in balls:
        x, y, dir = move(x, y, dir)
        new[x][y] = ball
        if x == 0 and y == 0:
            break
    return new


def bomb(balls):
    while balls:
        now = balls[0]
        start, end = 0, 0
        new_balls = []
        for i in range(1, len(balls)):
            if now == balls[i]:
                end = i
            else:
                if end - start >= 3:
                    new_balls.extend(balls[end+1:i])
                    answer.extend(balls[start:end+1])
                else:
                    new_balls.extend(balls[start:i])
                now = balls[i]
                start, end = i, i
        if end - start >= 3:
            answer.extend(balls[start:])
        else:
            new_balls.extend(balls[start:])

        if len(new_balls) == len(balls):
            balls = new_balls[:]
            break
        balls = new_balls[:]
    return balls


def group_make(balls):
    if balls:
        groups = [[1, balls[0]]]
        for i in range(1, len(balls)):
            if groups[-1][1] == balls[i]:
                groups[-1][0] += 1
            else:
                groups.append([1, balls[i]])
        new_balls = []
        for group in groups:
            new_balls.extend(group)
        return new_balls
    else:
        return balls


answer = []
for _ in range(m):
    d, s = map(int, input().split())
    d = dir_change(d)  # 이제 위오아왼순서
    # 구슬파괴
    destroy(d, s)
    # 남은 구슬 체크
    balls = collect_ball()
    # 구슬폭파
    balls = bomb(balls)
    balls = group_make(balls)
    # 구슬 채우기
    new = get_ball(balls)
    for i in range(n):
        graph[i] = new[i][:]
    # print(graph)

a, b = answer.count(1), answer.count(2)
c = len(answer) - a - b
print(a*1+b*2+c*3)
