import sys
input = sys.stdin.readline
n = int(input())
k = int(input())
s = set(map(int, input().split()))
l = list(s)
n = len(l)
l.sort()
distance = []
for i in range(n-1):
    distance.append(l[i+1]-l[i])

distance.sort()
print(sum(distance[:n-k]))
