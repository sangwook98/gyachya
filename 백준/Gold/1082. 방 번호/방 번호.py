import sys
input = sys.stdin.readline

n = int(input())
origin = list(map(int, input().split()))
m = int(input())
INF = 1e9
dp = [-INF]*(m+1)

for i in range(n-1, -1, -1):
    x = origin[i]
    for j in range(x, m+1):
        dp[j] = max(dp[j], i, dp[j-x]*10 + i)
print(dp[m])
