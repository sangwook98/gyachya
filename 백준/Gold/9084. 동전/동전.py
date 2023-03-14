import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    array = list(map(int, input().split()))
    m = int(input())
    dp = [0]*(max(m, max(array))+1)
    dp[0] = 1

    for i in range(n):
        dp[array[i]] += 1
        for j in range(array[i]+1, m+1):
            dp[j] += dp[j-array[i]]
    print(dp[m])
