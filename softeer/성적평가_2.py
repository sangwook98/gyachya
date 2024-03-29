import sys
input = sys.stdin.readline


def rank(li):
    maxi = 3001
    count = 0
    result = [0]*n
    res = 0
    for point, index in li:
        if maxi > point:
            maxi = point
            res = 0
        elif maxi == point:
            res += 1
        count += 1
        result[index] = count - res
    return result


n = int(input())
total = [[0, i] for i in range(n)]
rresult = []
for _ in range(3):
    a = list(map(int, input().split()))
    for i in range(n):
        total[i][0] += a[i]
    fi = [[a[i], i] for i in range(n)]
    fi.sort(reverse=True)
    rresult.append(rank(fi))

for i in range(3):
    for res in rresult[i]:
        print(res, end=" ")
    print(end="\n")

total.sort(reverse=True)
for res in rank(total):
    print(res, end=" ")
