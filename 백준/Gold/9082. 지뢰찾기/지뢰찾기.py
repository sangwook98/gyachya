t = int(input())
INF = 1e9


def main(hide, bomb, first, second):
    cnt = first + second
    for i in range(1, n-1):
        x = hide[i] - first - second
        if x == 0:
            first = second
            second = 0
        elif x == 1:
            first = second
            second = 1
            cnt += 1
        else:
            return 0

    # if hide[n-1] == 0:
    #     if first + second != 0:
    #         return 0
    # elif hide[n-1] == 1:
    #     if first + second != 1:
    #         return 0
    # elif hide[n-1] == 2:
    #     if first + second != 2:
    #         return 0
    return cnt


for _ in range(t):
    n = int(input())
    hide = [int(p) for p in input()]
    bomb = [p for p in input()]

    box = []

    if hide[0] == 0:
        box.append(main(hide, bomb, 0, 0))
    elif hide[0] == 1:
        box.append(main(hide, bomb, 1, 0))
        box.append(main(hide, bomb, 0, 1))
    elif hide[0] == 2:
        box.append(main(hide, bomb, 1, 1))

    print(max(box))
