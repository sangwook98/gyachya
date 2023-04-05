import sys
import math
input = sys.stdin.readline
n, l = map(int, input().split())
dumps = [list(map(int, input().split())) for _ in range(n)]
dumps.sort()

start, end = -1, -1
answer = 0
for x_1, x_2 in dumps:
    if end < x_1:
        start = x_1
    else:
        start = end + 1
    # print('x_1,x_2,start', x_1, x_2, start)
    a = math.ceil((x_2 - start)/l)
    end = start + a*l - 1
    answer += a
    # print('answer,start,end', answer, start, end)
print(answer)
