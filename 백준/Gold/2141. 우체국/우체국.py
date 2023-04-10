import sys
input = sys.stdin.readline
n = int(input())
towns = []
human = 0
for _ in range(n):
    a, b = map(int, input().split())
    human += b
    towns.append((a, b))
towns.sort()

mid = human/2
cnt = 0
for i in range(n):
    cnt += towns[i][1]
    if cnt >= mid:
        print(towns[i][0])
        break
