word1 = list(input().rstrip())
word2 = list(input().rstrip())

n = len(word1)
m = len(word2)

if n > m:
    n, m = m, n
    word1, word2 = word2[:], word1[:]

dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if word1[i-1] == word2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
print(dp[n][m])
