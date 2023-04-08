t = int(input())


def main(words):
    n = len(words)
    left = 0
    right = n-1
    count = 0
    while left < right:
        if words[left] == words[right]:
            left += 1
            right -= 1
        else:
            a = words[left:right]
            r_a = a[::-1]
            b = words[left+1:right+1]
            r_b = b[::-1]
            if a == r_a or b == r_b:
                count = 1
                break
            else:
                count = 2
                break

    return count


for _ in range(t):
    print(main(input()))
