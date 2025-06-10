\
import sys
sys.setrecursionlimit(1000000)

# Baekjoon 2667 - 단지번호붙이기
N = int(sys.stdin.readline())
grid = [list(map(int, sys.stdin.readline().strip())) for _ in range(N)]

visited = [[False] * N for _ in range(N)]
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
sizes = []

def dfs(x: int, y: int) -> int:
    stack = [(x, y)]
    visited[x][y] = True
    count = 0
    while stack:
        cx, cy = stack.pop()
        count += 1
        for dx, dy in dirs:
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and grid[nx][ny] == 1:
                visited[nx][ny] = True
                stack.append((nx, ny))
    return count

for i in range(N):
    for j in range(N):
        if grid[i][j] == 1 and not visited[i][j]:
            sizes.append(dfs(i, j))

sizes.sort()
print(len(sizes))
print("\n".join(map(str, sizes)))
