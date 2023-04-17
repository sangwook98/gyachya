import sys
input = sys.stdin.readline
n = int(input())


a = list(map(int, input().split()))
b = list(map(int, input().split()))
diff = [b[i] - a[i] for i in range(n)]


answer = 0
prev = 0
for i in range(n):
    if prev < 0 and diff[i] < 0:
        if prev > diff[i]:
            answer += prev - diff[i]
    elif prev > 0 and diff[i] > 0:
        if prev < diff[i]:
            answer += diff[i] - prev
    else:
        answer += abs(diff[i])
    prev = diff[i]
print(answer)
