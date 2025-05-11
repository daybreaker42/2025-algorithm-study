import sys
input = sys.stdin.read
def solve():
    data = list(map(float, input().split()))
    n = int(data[0])
    drinks = sorted(data[1:])
    result = drinks[-1]
    for i in range(n-1):
        result += drinks[i] / 2
    print(int(result) if result == int(result) else result)
if __name__ == "__main__":
    solve()
