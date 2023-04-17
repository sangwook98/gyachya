import sys
input = sys.stdin.readline
n = int(input())
not_zero = [False]*10
check = [0]*10
alpha = [[0, i] for i in range(10)]

for _ in range(n):
    a = list(input().rstrip())
    length = len(a)

    for j in range(length):
        index = ord(a[j]) - ord('A')
        check[index] = 1
        if j == 0:
            not_zero[index] = True
        alpha[index][0] += 10 ** (length-1-j)

alpha.sort()

# check 0 need?
if sum(check) == 10:
    for i in range(10):
        index = alpha[i][1]
        if not not_zero[index]:
            alpha[i][0] = 0
            break

answer = 0
num, i = 9, 9
while num >= 0:
    if alpha[num][0]:
        answer += alpha[num][0]*i
        i -= 1
    num -= 1

print(answer)
