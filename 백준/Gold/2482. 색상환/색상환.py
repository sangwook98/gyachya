n = int(input())
k = int(input())

dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(4, n+1):
    dp[i][1] = i

for j in range(2, n//2 + 1):
    dp[j*2][j] = 2
    for i in range(j*2+1, n+1):
        if i == 5 and j == 2:
            dp[i][j] = 5
        else:
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % 1000000003
print(dp[n][k])
