\
import sys
from collections import deque

# Baekjoon 2178 - 미로탐색
N, M = map(int, sys.stdin.readline().split())
maze = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(N)]

dist = [[-1] * M for _ in range(N)]
dist[0][0] = 1
q = deque([(0, 0)])
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

while q:
    x, y = q.popleft()
    for dx, dy in dirs:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and maze[nx][ny] == 1 and dist[nx][ny] == -1:
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))

print(dist[N - 1][M - 1])
