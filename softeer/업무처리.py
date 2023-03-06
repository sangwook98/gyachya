import sys
from collections import deque
input = sys.stdin.readline
h, k, r = map(int, input().split())
nodes = [[[deque(), deque()] for _ in range(2**i)] for i in range(h)]
leaf = [deque(list(map(int, input().split()))) for _ in range(2**h)]

time = 1
answer = 0
while time <= r:
    # boss
    if time % 2 and nodes[0][0][0]:
        answer += nodes[0][0][0].popleft()
    elif time % 2 == 0 and nodes[0][0][1]:
        answer += nodes[0][0][1].popleft()

    # nodes
    for i in range(1, h):
        for j in range(len(nodes[i])):
            if time % 2 and nodes[i][j][0]:
                nodes[i-1][j//2][j % 2].append(nodes[i][j][0].popleft())
            elif time % 2 == 0 and nodes[i][j][1]:
                nodes[i-1][j//2][j % 2].append(nodes[i][j][1].popleft())
    # leaf
    for i in range(2**h):
        if leaf[i]:
            nodes[-1][i//2][i % 2].append(leaf[i].popleft())
    time += 1
print(answer)
