import sys
input = sys.stdin.readline
a = list(input().rstrip())
b = list(input().rstrip())

n = len(a)

while n != len(b):
    if b[-1] == 'A':
        b.pop()
    elif b[-1] == 'B':
        b.pop()
        b = b[::-1]

if a == b:
    print(1)
else:
    print(0)
