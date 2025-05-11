import sys
input = sys.stdin.read
def solve():
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx += 1
    results = []
    for _ in range(T):
        n = int(data[idx])
        idx += 1
        sticker = [[0] * (n+1) for _ in range(2)]
        dp = [[0] * (n+1) for _ in range(2)]
        for i in range(2):
            for j in range(1, n+1):
                sticker[i][j] = int(data[idx])
                idx += 1
        dp[0][1] = sticker[0][1]
        dp[1][1] = sticker[1][1]
        for j in range(2, n+1):
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + sticker[0][j]
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + sticker[1][j]
        results.append(str(max(dp[0][n], dp[1][n])))
    print('\n'.join(results))
if __name__ == "__main__":
    solve()
