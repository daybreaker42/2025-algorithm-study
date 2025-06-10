\
import sys
from collections import deque

# Baekjoon 13549 - 숨바꼭질 3
N, K = map(int, sys.stdin.readline().split())
MAX = 100000
dist = [-1] * (MAX + 1)

dq = deque([N])
dist[N] = 0

while dq:
    x = dq.popleft()
    if x == K:
        print(dist[x])
        break
    # teleport (cost 0)
    if x * 2 <= MAX and dist[x * 2] == -1:
        dist[x * 2] = dist[x]
        dq.appendleft(x * 2)
    # walk (cost 1)
    for nx in (x - 1, x + 1):
        if 0 <= nx <= MAX and dist[nx] == -1:
            dist[nx] = dist[x] + 1
            dq.append(nx)
