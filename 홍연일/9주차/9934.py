\
import sys
sys.setrecursionlimit(1000000)

# Baekjoon 9934 - 완전 이진 트리
K = int(sys.stdin.readline())
inorder = list(map(int, sys.stdin.readline().split()))

levels = [[] for _ in range(K)]

def build(level: int, arr: list[int]):
    if not arr:
        return
    mid = len(arr) // 2
    levels[level].append(arr[mid])
    if level + 1 < K:
        build(level + 1, arr[:mid])
        build(level + 1, arr[mid + 1:])

build(0, inorder)
for lv in levels:
    print(*lv)
