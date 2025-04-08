import sys
import heapq

n = int(sys.stdin.readline())
abs_heap = []

for _ in range(n):
    command = int(sys.stdin.readline())
    
    if command != 0:
        # Store as (absolute value, original value)
        heapq.heappush(abs_heap, (abs(command), command))
    else:
        if not abs_heap:
            print(0)
        else:
            # Print the original value
            print(heapq.heappop(abs_heap)[1])
