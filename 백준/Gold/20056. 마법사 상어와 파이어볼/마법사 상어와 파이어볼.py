import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
fireballs = [list(map(int, input().split())) for _ in range(m)]

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

for _ in range(k):
    tmp = {}
    new = []

    for ball in fireballs:
        [x, y, m, s, d] = ball
        nx = (x + s*dx[d]) % n
        ny = (y + s*dy[d]) % n
        if tmp.get((nx, ny)):
            tmp[(nx, ny)].append((m, s, d))
        else:
            tmp[(nx, ny)] = [(m, s, d)]

    # 파이어볼 합체
    for key, values in tmp.items():

        if len(values) == 1:
            new.append(key + values[0])
            continue

        mass = 0
        velocity = 0
        dir = set()
        for value in values:
            m, s, d = value
            mass += m
            velocity += s
            dir.add(d % 2)

        if mass//5 > 0:
            if len(dir) == 1:
                for j in 0, 2, 4, 6:
                    new.append(key + (mass//5, velocity//(len(values)), j))
            elif len(dir) == 2:
                for j in 1, 3, 5, 7:
                    new.append(key + (mass//5, velocity//(len(values)), j))

    fireballs = new
    # print(fireballs)

answer = 0
for ball in fireballs:
    _, _, m, _, _ = ball
    answer += m
print(answer)
