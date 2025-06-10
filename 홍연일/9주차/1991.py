\
import sys

# Baekjoon 1991 - 트리 순회
n = int(sys.stdin.readline())
tree = {}
for _ in range(n):
    p, l, r = sys.stdin.readline().split()
    tree[p] = (l, r)

pre, ino, post = [], [], []

def traverse(node):
    if node == '.':
        return
    l, r = tree[node]
    pre.append(node)
    traverse(l)
    ino.append(node)
    traverse(r)
    post.append(node)

traverse('A')
print(''.join(pre))
print(''.join(ino))
print(''.join(post))
