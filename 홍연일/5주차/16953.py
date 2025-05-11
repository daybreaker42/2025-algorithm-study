import sys
input = sys.stdin.read
def solve():
    a, b = map(int, input().split())
    count = 1
    while a < b:
        if b % 2 == 0:
            b //= 2
        elif b % 10 == 1:
            b //= 10
        else:
            print(-1)
            return
        count += 1
    print(count if a == b else -1)
if __name__ == "__main__":
    solve()
