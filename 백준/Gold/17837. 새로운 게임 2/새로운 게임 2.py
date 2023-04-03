n, k = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
pos = [list(map(lambda x: int(x)-1, input().split())) for _ in range(k)]
board = [[[] for _ in range(n)] for _ in range(n)]
for num in range(len(pos)):
    x, y, _ = pos[num]
    board[x][y].append(num)

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def white(num, x, y, nx, ny):
    index = board[x][y].index(num)

    for num in board[x][y][index:]:
        pos[num][0], pos[num][1] = nx, ny

    board[nx][ny].extend(board[x][y][index:])
    board[x][y] = board[x][y][:index]

    if len(board[nx][ny]) >= 4:
        return True
    else:
        return False


def red(num, x, y, nx, ny):
    index = board[x][y].index(num)

    for num in board[x][y][index:]:
        pos[num][0], pos[num][1] = nx, ny

    board[nx][ny].extend(board[x][y][index:][::-1])
    board[x][y] = board[x][y][:index]

    if len(board[nx][ny]) >= 4:
        return True
    else:
        return False


def blue(num, x, y, dir):
    dir = dir - 1 if dir % 2 else dir+1

    nx = x + dx[dir]
    ny = y + dy[dir]

    pos[num][2] = dir

    if not is_valid(nx, ny) or graph[nx][ny] == 2:
        return False
    elif graph[nx][ny] == 0:
        return white(num, x, y, nx, ny)
    elif graph[nx][ny] == 1:
        return red(num, x, y, nx, ny)


def pp():
    for i in board:
        print(i, sep='')
    print('----')


for time in range(1, 1001):
    for num in range(k):
        x, y, dir = pos[num]
        # print('x,y,dir', x, y, dir)
        nx = x + dx[dir]
        ny = y + dy[dir]

        if is_valid(nx, ny):
            if graph[nx][ny] == 0:
                Flag = white(num, x, y, nx, ny)
            elif graph[nx][ny] == 1:
                Flag = red(num, x, y, nx, ny)
            elif graph[nx][ny] == 2:
                Flag = blue(num, x, y, dir)
        else:
            Flag = blue(num, x, y, dir)

        # pp()
        if Flag:
            # pp()
            print(time)
            exit()
    # print('time--------------', time)


print(-1)
