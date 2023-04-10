import sys
input = sys.stdin.readline

n = int(input())
distance = []
human = 0
for i in range(1, n+1):
    a, b = map(int, input().split())
    distance.append([a, b])
    human += b
distance.sort()
cnt = 0
for i in range(n):
    cnt += distance[i][1]
    if cnt >= human/2:
        print(distance[i][0])
        break
