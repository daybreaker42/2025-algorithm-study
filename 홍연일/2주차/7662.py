import sys
import heapq
from collections import defaultdict

t = int(sys.stdin.readline())
for _ in range(t):
    k = int(sys.stdin.readline())
    min_heap = []
    max_heap = []
    removed = defaultdict(int)  # Track removed elements
    
    for _ in range(k):
        command, value = sys.stdin.readline().split()
        value = int(value)
        
        if command == 'I':
            heapq.heappush(min_heap, value)
            heapq.heappush(max_heap, -value)  # Negate for max heap
        elif command == 'D':
            if not min_heap:
                continue
                
            if value == 1:  # Remove maximum
                # Remove from max_heap and mark as removed
                while max_heap and removed[-max_heap[0]] > 0:
                    removed[-max_heap[0]] -= 1
                    heapq.heappop(max_heap)
                
                if max_heap:
                    removed[-heapq.heappop(max_heap)] += 1
                    
            elif value == -1:  # Remove minimum
                # Remove from min_heap and mark as removed
                while min_heap and removed[min_heap[0]] > 0:
                    removed[min_heap[0]] -= 1
                    heapq.heappop(min_heap)
                
                if min_heap:
                    removed[heapq.heappop(min_heap)] += 1
    
    # Clean up heaps
    while min_heap and removed[min_heap[0]] > 0:
        removed[min_heap[0]] -= 1
        heapq.heappop(min_heap)
        
    while max_heap and removed[-max_heap[0]] > 0:
        removed[-max_heap[0]] -= 1
        heapq.heappop(max_heap)
    
    if not min_heap or not max_heap:
        print("EMPTY")
    else:
        print(f"{-max_heap[0]} {min_heap[0]}")
