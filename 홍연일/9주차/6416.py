\
import sys
sys.setrecursionlimit(1000000)

# Baekjoon 6416 - 트리인가?
case_num = 1
edges = []
node_in = {}
uf_parent = {}

def find(x):
    if uf_parent[x] != x:
        uf_parent[x] = find(uf_parent[x])
    return uf_parent[x]

def union(a, b):
    ra, rb = find(a), find(b)
    if ra == rb:
        return False  # cycle
    uf_parent[rb] = ra
    return True

def is_tree():
    if not node_in:  # empty graph
        return True
    roots = {n for n, deg in node_in.items() if deg == 0}
    if len(roots) != 1:
        return False
    # check edges = nodes - 1 and no cycles via union-find
    total_nodes = len(node_in)
    if len(edges) != total_nodes - 1:
        return False
    for a, b in edges:
        if not union(a, b):
            return False
    return True

for line in sys.stdin:
    a, b = map(int, line.split())
    if a == -1 and b == -1:
        break
    if a == 0 and b == 0:
        result = is_tree()
        print(f"Case {case_num} is {'a tree.' if result else 'not a tree.'}")
        case_num += 1
        edges.clear()
        node_in.clear()
        uf_parent.clear()
        continue
    edges.append((a, b))
    if a not in uf_parent:
        uf_parent[a] = a
    if b not in uf_parent:
        uf_parent[b] = b
    # track indegrees
    node_in.setdefault(a, 0)
    node_in[b] = node_in.get(b, 0) + 1
