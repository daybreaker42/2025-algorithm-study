import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    n = data[0]
    wine = [0] + data[1:]
    dp = [0] * (n+1)
    if n >= 1: dp[1] = wine[1]
    if n >= 2: dp[2] = wine[1] + wine[2]
    for i in range(3, n+1):
        dp[i] = max(dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i])
    print(dp[n])
if __name__ == "__main__":
    solve()
