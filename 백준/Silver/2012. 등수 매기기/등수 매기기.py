import sys
input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)]
nums.sort()

answer = 0

for i in range(1, n+1):
    answer += abs(i-nums[i-1])

print(answer)
