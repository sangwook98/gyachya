n = int(input())
dp = [0] + [1]*9

INF = int(1e9)
for i in range(1, n):
    new_dp = [0]*10
    for j in range(10):
        if j == 0:
            new_dp[1] += dp[j]
        elif j == 9:
            new_dp[8] += dp[j]
        else:
            new_dp[j-1] += dp[j]
            new_dp[j+1] += dp[j]
    dp = [p % 10**9 for p in new_dp]
print(sum(dp) % 10**9)
