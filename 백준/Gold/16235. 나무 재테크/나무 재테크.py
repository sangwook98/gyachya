n, m, k = map(int, input().split())
graph = [[5]*n for _ in range(n)]
poop = [list(map(int, input().split())) for _ in range(n)]
trees = [[[] for _ in range(n)] for _ in range(n)]
deads = [[[] for _ in range(n)] for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    trees[a-1][b-1].append(c)

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


def is_valid(nx, ny):
    return 0 <= nx <= n-1 and 0 <= ny <= n-1


def spring_summer():
    for i in range(n):
        for j in range(n):
            tree = trees[i][j]
            index = len(tree)
            temp = 0
            for k in range(len(tree)-1, -1, -1):
                if tree[k] <= graph[i][j]:
                    graph[i][j] -= tree[k]
                    tree[k] += 1
                    index = k
                else:
                    temp += tree[k]//2

            graph[i][j] += temp
            trees[i][j] = tree[index:]


def fall_winter():
    # fall
    for i in range(n):
        for j in range(n):
            tree = trees[i][j]
            for k in range(len(tree)):
                if tree[k] % 5 == 0:
                    for p in range(8):
                        nx = i + dx[p]
                        ny = j + dy[p]
                        if is_valid(nx, ny):
                            trees[nx][ny].append(1)
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
    fall_winter()
    # print('{}년 끝'.format(l+1))

answer = 0
for i in range(n):
    for j in range(n):
        answer += len(trees[i][j])
print(answer)
