import sys
input = sys.stdin.readline

n = int(input())
size = [[] for _ in range(2001)]
color = [0]*n
Sum = 0

for i in range(n):
    c, s = map(int, input().split())
    size[s].append((c-1, i))
    Sum += s
    color[c-1] += s


answer = [0]*n

for siz in range(2000, 0, -1):
    for a, ind in size[siz]:
        Sum -= siz
        color[a] -= siz

    for a, ind in size[siz]:
        answer[ind] = Sum - color[a]

for ans in answer:
    print(ans)
