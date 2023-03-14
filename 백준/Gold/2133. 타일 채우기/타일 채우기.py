n = int(input())

dp = [0]*(n+2)
dp[0] = 1
dp[2] = 3
for i in range(4, n+1, 2):
    for j in range(2, i+1, 2):
        if j == 2:
            dp[i] += dp[i-j]*3
        else:
            dp[i] += dp[i-j]*2
print(dp[n])
