\
import sys
from collections import deque

# Baekjoon 14940 - 쉬운 최단거리
N, M = map(int, sys.stdin.readline().split())
field = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dist = [[-1] * M for _ in range(N)]
goal = None
for i in range(N):
    for j in range(M):
        if field[i][j] == 2:
            goal = (i, j)
            dist[i][j] = 0
        elif field[i][j] == 0:
            dist[i][j] = 0

if goal:
    q = deque([goal])
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while q:
        x, y = q.popleft()
        for dx, dy in dirs:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < M and field[nx][ny] == 1 and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))

for row in dist:
    print(" ".join(map(str, row)))
