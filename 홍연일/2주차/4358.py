import sys
from collections import defaultdict

tree_counts = defaultdict(int)
total_trees = 0

for line in sys.stdin:
    tree_name = line.strip()
    if not tree_name:
        break
    tree_counts[tree_name] += 1
    total_trees += 1

for tree_name in sorted(tree_counts.keys()):
    percentage = (tree_counts[tree_name] / total_trees) * 100.0
    print(f"{tree_name} {percentage:.4f}")
