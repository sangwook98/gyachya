import sys
input = sys.stdin.readline

x, y, w, s = map(int, input().split())

sx, sy = 0, 0
nx, ny = 0, 0
straight_good = True if 2*w < s else False
diagonal_good = True if w >= s else False
time = 0

if straight_good:
    time = w*(x+y)
else:
    if not diagonal_good:
        if x < y:
            time += s*x
            time += w*(y-x)
        else:
            time += s*y
            time += w*(x-y)
    else:
        if x == y:
            time = s*y
        elif x < y:
            mid = (x+y)//2
            if (x+y) % 2:
                time = s*(y-1) + w
            else:
                time = s*y
        else:
            mid = (x+y)//2
            if (x+y) % 2:
                time = s*(x-1) + w
            else:
                time = s*x


print(time)
