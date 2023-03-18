import sys
from collections import deque
input = sys.stdin.readline

q_t = [list(input().rstrip()) for _ in range(4)]


for _ in range(int(input())):
    a, b = map(int, input().split())
    q = deque([(a-1, b)])
    dir_check = [0]*4

    while q:
        num, dir = q.popleft()
        dir_check[num] = dir
        if num == 0:
            if q_t[num][2] != q_t[num+1][6] and dir_check[num+1] == 0:
                q.append((num+1, -1*dir))
        elif num == 1 or num == 2:
            if q_t[num][2] != q_t[num+1][6] and dir_check[num+1] == 0:
                q.append((num+1, -1*dir))
            if q_t[num][6] != q_t[num-1][2] and dir_check[num-1] == 0:
                q.append((num-1, -1*dir))
        elif num == 3:
            if q_t[num][6] != q_t[num-1][2] and dir_check[num-1] == 0:
                q.append((num-1, -1*dir))

    for i in range(4):
        # 시계방향
        if dir_check[i] == 1:
            a = q_t[i].pop()
            q_t[i].insert(0, a)
        # 반시계방향
        elif dir_check[i] == -1:
            a = q_t[i].pop(0)
            q_t[i].append(a)
answer = 0
for i in range(4):
    if q_t[i][0] == '1':
        answer += 2**i

print(answer)
