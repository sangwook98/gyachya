n = int(input())
grapes = [0] + [int(input()) for _ in range(n)]
dp = [0]*(n+1)
dp[1] = grapes[1]

for i in range(2, n+1):
    dp[i] = max(dp[i-1], grapes[i]+grapes[i-1]+dp[i-3], grapes[i]+dp[i-2])

print(dp[n])
