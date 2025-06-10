\
import sys
from collections import defaultdict, deque

# Baekjoon 20924 - 트리의 기둥과 가지
input = sys.stdin.readline
N, R = map(int, input().split())
adj = defaultdict(list)
for _ in range(N - 1):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))

parent = {R: 0}
trunk_len = 0
giga = R

# step 1: find giga node & trunk length
cur = R
prev = 0
while True:
    deg = len(adj[cur]) - (1 if prev else 0)
    if (prev == 0 and len(adj[cur]) != 1) or (prev != 0 and deg != 1):
        giga = cur
        break
    # go to the only child (degree ==1)
    for nxt, w in adj[cur]:
        if nxt != prev:
            trunk_len += w
            prev, cur = cur, nxt
            break

# step 2: find longest branch from giga
max_branch = 0
visited = set([giga])
dq = deque([(giga, 0)])
while dq:
    node, dist = dq.popleft()
    if node != giga and len(adj[node]) == 1:  # leaf
        max_branch = max(max_branch, dist)
    for nxt, w in adj[node]:
        if nxt not in visited:
            visited.add(nxt)
            dq.append((nxt, dist + w))

print(trunk_len, max_branch)
