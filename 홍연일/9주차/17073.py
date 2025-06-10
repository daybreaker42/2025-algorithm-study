\
import sys
from collections import defaultdict

# Baekjoon 17073 - 나무 위의 빗물
input = sys.stdin.readline
N, W = map(int, input().split())
deg = [0] * (N + 1)
for _ in range(N - 1):
    u, v = map(int, input().split())
    deg[u] += 1
    deg[v] += 1

leaf_cnt = sum(1 for i in range(2, N + 1) if deg[i] == 1)
print("{:.10f}".format(W / leaf_cnt))
