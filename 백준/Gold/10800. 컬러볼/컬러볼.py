import sys
input = sys.stdin.readline

n = int(input())
colors = [0]*n
result = [0]*n
balls = []
for i in range(n):
    balls.append(list(map(int, input().split()))+[i])

size_balls = sorted(balls, key=lambda x: (x[1], x[0]))

now, total = 0, 0
result_temp = 0
minus = 0
prev_color, prev_weight = size_balls[0][0], size_balls[0][1]
for i in range(n):
    [color, weight, index] = size_balls[i]

    if prev_color == color and weight == prev_weight:
        result[index] = result_temp
    else:
        if weight == prev_weight:
            minus = colors[color-1]
        else:
            now = total
            minus = colors[color-1]

        result[index] = now - minus
        result_temp = result[index]

    total += weight
    colors[color-1] += weight

    prev_color, prev_weight = color, weight

for res in result:
    print(res)
