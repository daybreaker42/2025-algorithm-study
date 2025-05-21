import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    N, K = data[0], data[1]
    A = [0] + data[2:]
    dp = [False] * (N+1)
    dp[1] = True
    for i in range(1, N):
        if not dp[i]:
            continue
        for j in range(i+1, N+1):
            energy = (j - i) * (1 + abs(A[i] - A[j]))
            if energy <= K:
                dp[j] = True
    print("YES" if dp[N] else "NO")
if __name__ == "__main__":
    solve()
