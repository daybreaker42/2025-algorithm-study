\
import sys

# Baekjoon 14675 - 단절점과 단절선
input = sys.stdin.readline
N = int(input())
deg = [0] * (N + 1)
edges = []
for _ in range(N - 1):
    u, v = map(int, input().split())
    deg[u] += 1
    deg[v] += 1
    edges.append((u, v))

Q = int(input())
for _ in range(Q):
    t, k = map(int, input().split())
    if t == 1:  # vertex
        print("yes" if deg[k] >= 2 else "no")
    else:  # edge
        print("yes")
