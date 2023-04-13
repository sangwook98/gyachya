import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    x, y = map(int, input().split())
    stores = []
    for i in range(n):
        a, b = map(int, input().split())
        dist = abs(a-x) + abs(b-y)
        stores.append((a, b, dist))
    festival = list(map(int, input().split()))
    stores = sorted(stores, key=lambda x: x[2])
    visited = [False]*n
    answer = 0
    q = deque([(x, y)])

    while q:
        nx, ny = q.popleft()
        if abs(festival[0] - nx) + abs(festival[1] - ny) <= 1000:
            answer = 1
            break

        for i in range(n):
            if not visited[i]:
                dist = abs(stores[i][0] - nx) + abs(stores[i][1] - ny)

                if dist <= 1000:
                    q.append((stores[i][0], stores[i][1]))
                    visited[i] = True

    if answer:
        print('happy')
    else:
        print('sad')
