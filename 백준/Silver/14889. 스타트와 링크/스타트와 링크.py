import sys
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [False]*n
answer = 10000000


def dfs(depth, index):
    global answer
    if depth == n//2:
        pow1, pow2 = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    pow1 += graph[i][j]
                elif not visited[i] and not visited[j]:
                    pow2 += graph[i][j]

        answer = min(answer, abs(pow1-pow2))
        return

    for i in range(index, n):
        if not visited[i]:
            visited[i] = True
            dfs(depth+1, i+1)
            visited[i] = False


dfs(0, 0)
print(answer)
