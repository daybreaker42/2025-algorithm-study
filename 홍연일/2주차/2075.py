import sys
import heapq

n = int(sys.stdin.readline())
min_heap = []  # We'll maintain a min heap of size n

for _ in range(n):
    row = list(map(int, sys.stdin.readline().split()))
    for num in row:
        if len(min_heap) < n:
            heapq.heappush(min_heap, num)
        elif num > min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, num)

# The smallest number in our heap of n largest numbers is the nth largest
print(min_heap[0])
