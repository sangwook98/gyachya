def main(words):
    n = len(words)
    left = 0
    right = n-1
    while left < right:
        if words[left] == words[right]:
            left += 1
            right -= 1
        else:
            a = words[left+1:right+1]
            b = words[left:right]
            if a == a[::-1] or b == b[::-1]:
                return 1
            else:
                return 2
    return 0


for _ in range(int(input())):
    print(main(input().rstrip()))
