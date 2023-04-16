import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

answer = [0]*n
answer[n-1] = -1
stack = [nums[-1]]

for i in range(n-2, -1, -1):
    while stack and stack[-1] <= nums[i]:
        stack.pop()

    if stack:
        answer[i] = stack[-1]
    else:
        answer[i] = -1
    stack.append(nums[i])
print(*answer)
