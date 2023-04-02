n = int(input())
graph = [[0]*(n+1)]+[[0]+list(map(int, input().split())) for _ in range(n)]
row_sum = [i[:] for i in graph]
for i in range(1, n+1):
    for j in range(1, n+1):
        row_sum[i][j] += row_sum[i][j-1]

answer = 40000

dx = [1, 1]  # 대각선오른쪽, 대각선 왼쪽
dy = [1, -1]


def is_valid(nx, ny):
    return 1 <= nx <= n and 1 <= ny <= n


for x in range(1, n-1):
    # for x in range(1, 2):
    for y in range(1, n+1):
        # print('x,y', x, y)
        candidate = []
        # d_1 찾기
        d_1 = 1
        while True:
            nx = x + d_1*dx[1]
            ny = y + d_1*dy[1]
            if is_valid(nx, ny):
                d_1 += 1
            else:
                break
        # d_2 찾기
        d_2 = 1
        while True:
            nx = x + d_2*dx[0]
            ny = y + d_2*dy[0]
            if is_valid(nx, ny):
                d_2 += 1
            else:
                break

        for b in range(d_2, 0, -1):
            for a in range(d_1, 0, -1):
                nx = x + a*dx[1]+b*dx[0]
                ny = y + a*dy[1]+b*dy[0]
                nnx = x + a*dx[1]
                nny = y + a*dy[1]
                nnnx = x + b*dx[0]
                nnny = y + b*dy[0]

                if is_valid(nx, ny) and is_valid(nnx, nny) and is_valid(nnnx, nnny):
                    candidate.append((a, b))
        # print(candidate)
        # 가능한 d_1, d_2로 구역들 인구수 구하기
        for a, b in candidate:
            # print(a, b)
            points = [0]*6
            for c in range(1, x):
                points[1] += row_sum[c][y]
                points[2] += row_sum[c][n] - row_sum[c][y]

            points[5] += graph[x][y]
            points[1] += row_sum[x][y-1]
            points[2] += row_sum[x][n] - row_sum[x][y]

            # print('points', points)
            right_x, right_y = x, y
            left_x, left_y = x, y

            for k in range(1, a+b+1):
                if k <= b:
                    right_x += dx[0]
                    right_y += dy[0]
                else:
                    right_x += dx[1]
                    right_y += dy[1]

                if k <= a:
                    left_x += dx[1]
                    left_y += dy[1]
                else:
                    left_x += dx[0]
                    left_y += dy[0]

                if k <= a-1:
                    points[1] += row_sum[left_x][left_y-1]
                else:
                    points[3] += row_sum[left_x][left_y-1]

                if k <= b:
                    points[2] += row_sum[right_x][n] - \
                        row_sum[right_x][right_y]
                else:
                    points[4] += row_sum[right_x][n] - \
                        row_sum[right_x][right_y]

                points[5] += row_sum[right_x][right_y] - \
                    row_sum[left_x][left_y-1]
                # print('points', points)

            for c in range(left_x+1, n+1):
                points[3] += row_sum[c][left_y-1]
                points[4] += row_sum[c][n] - row_sum[c][left_y-1]
                # print('points', points)

            answer = min(answer, max(points[1:]) - min(points[1:]))
            # print('answer, now', answer, max(points[1:]) - min(points[1:]))
            if answer == 0:
                print(0)
                exit()
print(answer)
# 4
# 1 2 3 4
# 5 6 7 8
# 9 10 11 12
# 13 14 15 16

# 5
# 1 2 3 4 5
# 6 7 8 9 10
# 11 12 13 14 15
# 16 17 18 19 20
# 21 22 23 24 25
