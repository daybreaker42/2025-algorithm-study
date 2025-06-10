import sys

# Baekjoon 12865 - 평범한 배낭 (0-1 Knapsack)
input = sys.stdin.readline
N, K = map(int, input().split())

dp = [0] * (K + 1)

for _ in range(N):
    w, v = map(int, input().split())
    # Traverse weights in reverse to avoid reusing the same item
    for weight in range(K, w - 1, -1):
        dp[weight] = max(dp[weight], dp[weight - w] + v)

print(dp[K])
