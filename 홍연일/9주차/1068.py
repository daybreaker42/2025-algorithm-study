\
import sys
sys.setrecursionlimit(1000000)

# Baekjoon 1068 - 트리
input = sys.stdin.readline
N = int(input())
parents = list(map(int, input().split()))
erase = int(input())

adj = [[] for _ in range(N)]
root = -1
for child, p in enumerate(parents):
    if p == -1:
        root = child
    else:
        adj[p].append(child)

if erase == root:
    print(0)
    sys.exit()

def dfs(node):
    if node == erase:
        return 0
    if not adj[node] or (len(adj[node]) == 1 and adj[node][0] == erase):
        return 1  # leaf
    cnt = 0
    for child in adj[node]:
        cnt += dfs(child)
    return cnt

print(dfs(root))
