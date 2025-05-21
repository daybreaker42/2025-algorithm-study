import sys
input = sys.stdin.read
def solve():
    data = input().split()
    s = data[1]
    blue, red = 0, 0
    prev = ''
    for c in s:
        if c != prev:
            if c == 'B':
                blue += 1
            else:
                red += 1
            prev = c
    print(min(blue, red) + 1)
if __name__ == "__main__":
    solve()
