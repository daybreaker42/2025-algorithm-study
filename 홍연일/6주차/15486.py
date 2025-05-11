import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    N = data[0]
    T = [0] * (N+2)
    P = [0] * (N+2)
    dp = [0] * (N+2)
    for i in range(1, N+1):
        T[i] = data[2*i - 1]
        P[i] = data[2*i]
    for i in range(1, N+1):
        dp[i] = max(dp[i], dp[i-1])
        if i + T[i] <= N+1:
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i])
    print(max(dp[N], dp[N+1]))
if __name__ == "__main__":
    solve()
