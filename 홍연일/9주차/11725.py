\
import sys
from collections import deque

# Baekjoon 11725 - 트리의 부모 찾기
input = sys.stdin.readline
N = int(input())
adj = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

parent = [0] * (N + 1)
visited = [False] * (N + 1)
dq = deque([1])
visited[1] = True

while dq:
    cur = dq.popleft()
    for nxt in adj[cur]:
        if not visited[nxt]:
            visited[nxt] = True
            parent[nxt] = cur
            dq.append(nxt)

for i in range(2, N + 1):
    print(parent[i])
