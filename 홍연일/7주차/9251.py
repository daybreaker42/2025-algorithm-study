import sys

# Baekjoon 9251 - LCS
str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()

len1, len2 = len(str1), len(str2)
dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

for i in range(1, len1 + 1):
    for j in range(1, len2 + 1):
        if str1[i - 1] == str2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[len1][len2])
