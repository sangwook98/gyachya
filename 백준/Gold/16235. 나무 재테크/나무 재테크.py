n, m, k = map(int, input().split())
graph = [[5]*n for _ in range(n)]
poop = [list(map(int, input().split())) for _ in range(n)]
trees = [[{} for _ in range(n)] for _ in range(n)]


for _ in range(m):
    a, b, c = map(int, input().split())
    trees[a-1][b-1][c] = 1

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def spring_summer():
    for i in range(n):
        for j in range(n):
            if trees[i][j]:
                die = 0
                survived = 0
                temp = {}

                for age in sorted(trees[i][j].keys()):
                    if trees[i][j][age]*age <= graph[i][j]:
                        graph[i][j] -= trees[i][j][age]*age
                        temp[age+1] = trees[i][j][age]
                    else:
                        survived = graph[i][j] // age

                        if not survived:
                            die += (trees[i][j][age] - survived)*(age // 2)
                            continue
                        graph[i][j] -= survived*age
                        die += (trees[i][j][age] - survived)*(age // 2)

                        temp[age+1] = survived
                trees[i][j] = temp
                graph[i][j] += die


def fall_winter():
    # fall
    for i in range(n):
        for j in range(n):
            if trees[i][j]:
                tmp = 0
                for age in trees[i][j].keys():
                    if age % 5 == 0:
                        tmp += trees[i][j][age]

                if tmp > 0:
                    for p in range(8):
                        nx = i + dx[p]
                        ny = j + dy[p]
                        if is_valid(nx, ny):
                            trees[nx][ny][1] = trees[nx][ny].get(1, 0) + tmp
            # winter
            graph[i][j] += poop[i][j]


def pp():
    for i in trees:
        print(i, sep='')
    print('++')
    for i in graph:
        print(i, sep='')
    print('-------')


for l in range(k):
    spring_summer()
    # pp()
    fall_winter()
    # pp()
    # print('{}년 끝'.format(l+1))

answer = 0
for i in range(n):
    for j in range(n):
        for value in trees[i][j].values():
            answer += value
print(answer)
