\
import sys
from collections import deque

# Baekjoon 17836 - 공주님을 구해라!
N, M, T = map(int, sys.stdin.readline().split())
castle = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

INF = 10 ** 9
dist = [[INF] * M for _ in range(N)]
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

q = deque([(0, 0)])
dist[0][0] = 0
sword_pos = None

while q:
    x, y = q.popleft()
    for dx, dy in dirs:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and castle[nx][ny] != 1 and dist[nx][ny] == INF:
            dist[nx][ny] = dist[x][y] + 1
            if castle[nx][ny] == 2:
                sword_pos = (nx, ny)
            q.append((nx, ny))

ans = dist[N - 1][M - 1]

if sword_pos:
    sx, sy = sword_pos
    via_sword = dist[sx][sy] + abs(N - 1 - sx) + abs(M - 1 - sy)
    ans = min(ans, via_sword)

print(ans if ans <= T else "Fail")
