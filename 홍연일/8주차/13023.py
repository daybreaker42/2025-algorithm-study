\
import sys
sys.setrecursionlimit(1000000)

# Baekjoon 13023 - ABCDE
N, M = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

visited = [False] * N
found = False

def dfs(v: int, depth: int):
    global found
    if found:
        return
    if depth == 5:
        found = True
        return
    visited[v] = True
    for nxt in adj[v]:
        if not visited[nxt]:
            dfs(nxt, depth + 1)
    visited[v] = False

for i in range(N):
    dfs(i, 1)
    if found:
        break

print(1 if found else 0)
