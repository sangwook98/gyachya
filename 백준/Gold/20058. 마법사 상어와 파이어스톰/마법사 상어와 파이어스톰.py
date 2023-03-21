import sys
input = sys.stdin.readline

n, q = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(2**n)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
Ls = list(map(int, input().split()))


# def turn(L):
#     new = [[0]*(2**n) for _ in range(2**n)]
#     # 시작점
#     for i in range(0, 2**n, 2**L):
#         for j in range(0, 2**n, 2**L):
#             # 90도 돌리기
#             tmp = [graph[k][j:j+2**L] for k in range(i, i+2**L)]
#             new_tmp = [[0]*2**L for _ in range(2**L)]
#             for x in range(2**L):
#                 for y in range(2**L):
#                     new_tmp[y][2**L-x-1] = tmp[x][y]

#             for x in range(2**L):
#                 for y in range(2**L):
#                     new[i+x][j+y] = new_tmp[x][y]

#     for i in range(2**n):
#         graph[i] = new[i][:]


def turn(L):
    new = [[0]*(2**n) for _ in range(2**n)]
    # 시작점
    for i in range(0, 2**n, 2**L):
        for j in range(0, 2**n, 2**L):
            # 90도 돌리기
            for x in range(2**L):
                for y in range(2**L):
                    new[i+y][j+2**L - x - 1] = graph[i+x][j+y]

    for i in range(2**n):
        graph[i] = new[i][:]


def melt():
    maybe = []
    for x in range(2**n):
        for y in range(2**n):
            if graph[x][y]:
                cnt = 0
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if is_valid(nx, ny) and graph[nx][ny] > 0:
                        cnt += 1

                if cnt < 3:
                    maybe.append((x, y))

    for a, b in maybe:
        graph[a][b] -= 1


def is_valid(nx, ny):
    return 0 <= nx <= 2**n-1 and 0 <= ny <= 2**n-1


# 돌리고 녹이기 시작
for L in Ls:
    turn(L)
    melt()

answer = [0, 0]
# 남아있는 얼음들의 합
for i in range(2**n):
    answer[0] += sum(graph[i])


# 남아있는 가장 큰 덩어리 찾기
check = [[False]*(2**n) for _ in range(2**n)]
for i in range(2**n):
    for j in range(2**n):
        if not check[i][j] and graph[i][j]:
            check[i][j] = True
            q = [(i, j)]
            cnt = 1
            while q:
                x, y = q.pop()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if is_valid(nx, ny) and not check[nx][ny] and graph[nx][ny]:
                        check[nx][ny] = True
                        q.append((nx, ny))
                        cnt += 1
            answer[1] = max(answer[1], cnt)
print(*answer, sep='\n')
