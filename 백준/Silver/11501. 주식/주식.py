import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    stocks = list(map(int, input().split()))
    maxi = [0]*n
    maximum = 0
    for i in range(n-1, -1, -1):
        if stocks[i] > maximum:
            maximum = stocks[i]
        maxi[i] = maximum
    answer = 0
    for i in range(n):
        answer += maxi[i]-stocks[i]
    print(answer)
