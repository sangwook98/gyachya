import sys
input = sys.stdin.readline
n = map(int, input().split())
chains = list(map(int, input().split()))
chains.sort(reverse=True)
answer = 0
index = 0
while index < len(chains)-1:
    if chains[-1]:
        chains[-1] -= 1
        index += 1
        answer += 1
    else:
        chains.pop()
print(answer)
