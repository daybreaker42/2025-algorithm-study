import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    N, M = data[0], data[1]
    idx = 2
    arr = [[0] * (N+1) for _ in range(N+1)]
    dp = [[0] * (N+1) for _ in range(N+1)]
    for i in range(1, N+1):
        for j in range(1, N+1):
            arr[i][j] = data[idx]
            idx += 1
    for i in range(1, N+1):
        for j in range(1, N+1):
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j]
    results = []
    for _ in range(M):
        x1, y1, x2, y2 = data[idx:idx+4]
        idx += 4
        res = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]
        results.append(str(res))
    print('\n'.join(results))
if __name__ == "__main__":
    solve()
