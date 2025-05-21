import sys
import heapq
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    n = data[0]
    lectures = [(data[i], data[i+1]) for i in range(1, 2*n, 2)]
    lectures.sort()
    rooms = [lectures[0][1]]
    for start, end in lectures[1:]:
        if start >= rooms[0]:
            heapq.heappop(rooms)
        heapq.heappush(rooms, end)
    print(len(rooms))
if __name__ == "__main__":
    solve()
