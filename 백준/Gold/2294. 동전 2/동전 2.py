import sys
input = sys.stdin.readline
n, k = map(int, input().split())
array = [int(input()) for _ in range(n)]
array.sort()

dp = [int(1e9)]*(k+1)
dp[0] = 0

for i in array:
    for j in range(i, k+1):
        dp[j] = min(dp[j-i]+1, dp[j])
print(dp[k] if not dp[k] == int(1e9) else -1)
