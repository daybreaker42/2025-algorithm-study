import sys
import heapq
from collections import defaultdict

n = int(sys.stdin.readline())
max_heap = []  # (-difficulty, -problem_id) for max heap
min_heap = []  # (difficulty, problem_id) for min heap
problem_difficulty = {}  # Map: problem_id -> difficulty
deleted = set()  # Track deleted problems

for _ in range(n):
    p, l = map(int, sys.stdin.readline().split())
    heapq.heappush(max_heap, (-l, -p))
    heapq.heappush(min_heap, (l, p))
    problem_difficulty[p] = l

m = int(sys.stdin.readline())
for _ in range(m):
    operation = sys.stdin.readline().split()
    
    if operation[0] == "add":
        p, l = int(operation[1]), int(operation[2])
        heapq.heappush(max_heap, (-l, -p))
        heapq.heappush(min_heap, (l, p))
        problem_difficulty[p] = l
        
    elif operation[0] == "recommend":
        x = int(operation[1])
        
        if x == 1:  # Find hardest problem
            # Remove deleted problems
            while max_heap and -max_heap[0][1] in deleted:
                heapq.heappop(max_heap)
                
            if max_heap:
                print(-max_heap[0][1])
                
        elif x == -1:  # Find easiest problem
            # Remove deleted problems
            while min_heap and min_heap[0][1] in deleted:
                heapq.heappop(min_heap)
                
            if min_heap:
                print(min_heap[0][1])
                
    elif operation[0] == "solved":
        p = int(operation[1])
        deleted.add(p)  # Mark as deleted instead of removing from heaps
        del problem_difficulty[p]
