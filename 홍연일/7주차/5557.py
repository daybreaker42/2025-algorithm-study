import sys

# Baekjoon 5557 - 1학년
N = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))

dp = [0] * 21
dp[numbers[0]] = 1

for idx in range(1, N - 1):
    nxt = [0] * 21
    num = numbers[idx]
    for val in range(21):
        if dp[val]:
            if val + num <= 20:
                nxt[val + num] += dp[val]
            if val - num >= 0:
                nxt[val - num] += dp[val]
    dp = nxt

print(dp[numbers[-1]])
