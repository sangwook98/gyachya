papers = [int(input()) for _ in range(6)]
papers.insert(0, 0)
cnt = 0


def cut(i, total):

    while papers[i] and total:
        papers[i] -= 1
        total -= i**2
    return total


for i in range(6, 0, -1):
    while papers[i] > 0:
        cnt += 1

        if i == 6:
            papers[i] -= 1

        elif i == 5:
            papers[i] -= 1
            papers[1] = max(papers[1]-11, 0)

        elif i == 4:
            total = 20
            papers[i] -= 1
            total = cut(2, total)
            total = cut(1, total)

        elif i == 3:
            if 4 <= papers[i]:
                papers[i] -= 4

            elif papers[i] == 3:
                papers[i] = 0
                if papers[2]:
                    papers[2] -= 1
                    total = 5
                    total = cut(1, total)
                else:
                    papers[i] = max(papers[i]-9, 0)

            elif papers[i] == 2:
                papers[i] = 0
                a = cut(2, 12)
                total = cut(1, a+6)

            elif papers[i] == 1:
                papers[i] = 0
                total = 27
                a = cut(2, 20)
                total = cut(1, a+7)

        elif i == 2:
            total = 36
            if 9 <= papers[i]:
                papers[i] -= 9
            else:
                total = cut(2, total)
                total = cut(1, total)

        elif i == 1:
            papers[i] = max(papers[i]-36, 0)
print(cnt)
