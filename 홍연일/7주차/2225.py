import sys

# Baekjoon 2225 - 합분해
MOD = 1_000_000_000
N, K = map(int, sys.stdin.readline().split())

# dp[n] : 현재 단계(k개)에서 합이 n이 되는 경우의 수
dp = [1] * (N + 1)  # k = 1 초기값

for _ in range(1, K):  # 2번째 수부터 K번째 수까지
    new = [0] * (N + 1)
    cumulative = 0
    for n in range(N + 1):
        cumulative = (cumulative + dp[n]) % MOD
        new[n] = cumulative
    dp = new

print(dp[N] % MOD)
