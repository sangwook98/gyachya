import sys
input = sys.stdin.readline
n, m = map(int, input().split())

course = []
for i in range(n):
    a, b = map(int, input().split())
    box = list(map(int, input().split()))

    if len(box) < b:
        course.append(1)
    else:
        box.sort(reverse=True)
        course.append(box[b-1])
course.sort()
cnt = 0
for cours in course:
    if m - cours >= 0:
        m -= cours
        cnt += 1
    else:
        break
print(cnt)
