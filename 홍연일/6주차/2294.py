import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    n, k = data[0], data[1]
    coins = data[2:2+n]
    dp = [float('inf')] * (k+1)
    dp[0] = 0
    for coin in coins:
        for j in range(coin, k+1):
            dp[j] = min(dp[j], dp[j - coin] + 1)
    print(-1 if dp[k] == float('inf') else dp[k])
if __name__ == "__main__":
    solve()
