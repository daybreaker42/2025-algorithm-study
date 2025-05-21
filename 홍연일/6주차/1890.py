import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    N = data[0]
    board = [data[i*N+1:(i+1)*N+1] for i in range(N)]
    dp = [[0] * N for _ in range(N)]
    dp[0][0] = 1
    for i in range(N):
        for j in range(N):
            if dp[i][j] == 0 or (i == N-1 and j == N-1):
                continue
            jump = board[i][j]
            if j + jump < N:
                dp[i][j + jump] += dp[i][j]
            if i + jump < N:
                dp[i + jump][j] += dp[i][j]
    print(dp[N-1][N-1])
if __name__ == "__main__":
    solve()
