import sys

# Baekjoon 15724 - 주지수
input = sys.stdin.readline
N, M = map(int, input().split())
prefix = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    row = list(map(int, input().split()))
    for j in range(1, M + 1):
        prefix[i][j] = (
            row[j - 1]
            + prefix[i - 1][j]
            + prefix[i][j - 1]
            - prefix[i - 1][j - 1]
        )

T = int(input())
answers = []
for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    res = (
        prefix[x2][y2]
        - prefix[x1 - 1][y2]
        - prefix[x2][y1 - 1]
        + prefix[x1 - 1][y1 - 1]
    )
    answers.append(str(res))

sys.stdout.write("\n".join(answers))
