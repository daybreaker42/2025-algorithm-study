\
import sys
from collections import deque

# Baekjoon 1325 - 효율적인 해킹
input = sys.stdin.readline
N, M = map(int, input().split())
rev_adj = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    rev_adj[b].append(a)  # reverse edge

def bfs(start: int) -> int:
    visited = [False] * (N + 1)
    visited[start] = True
    q = deque([start])
    cnt = 1
    while q:
        cur = q.popleft()
        for nxt in rev_adj[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                cnt += 1
                q.append(nxt)
    return cnt

max_cnt = 0
result = []
for i in range(1, N + 1):
    c = bfs(i)
    if c > max_cnt:
        max_cnt = c
        result = [i]
    elif c == max_cnt:
        result.append(i)

print(*result)
