\
import sys

# Baekjoon 16918 - 봄버맨
R, C, N = map(int, sys.stdin.readline().split())
grid = [list(sys.stdin.readline().strip()) for _ in range(R)]

if N == 1:
    print("\n".join("".join(row) for row in grid))
    sys.exit()

if N % 2 == 0:
    print("\n".join("O" * C for _ in range(R)))
    sys.exit()

def explode(src):
    res = [["O"] * C for _ in range(R)]
    dirs = [(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1)]
    for i in range(R):
        for j in range(C):
            if src[i][j] == "O":
                for dx, dy in dirs:
                    nx, ny = i + dx, j + dy
                    if 0 <= nx < R and 0 <= ny < C:
                        res[nx][ny] = "."
    return res

first = explode(grid)
result = first if N % 4 == 3 else explode(first)
print("\n".join("".join(row) for row in result))
