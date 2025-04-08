import heapq
import sys

n = int(sys.stdin.readline())
max_heap = []

for _ in range(n):
    command = int(sys.stdin.readline())
    if command > 0:
        # Python's heapq is a min heap, so we negate values for max heap behavior
        heapq.heappush(max_heap, -command)
    else:
        if not max_heap:
            print(0)
        else:
            # Negate again when retrieving to get the original value
            print(-heapq.heappop(max_heap))
