import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    n = data[0]
    cranes = data[1:n+1]
    m = data[n+1]
    boxes = data[n+2:]
    cranes.sort(reverse=True)
    boxes.sort(reverse=True)
    if boxes[0] > cranes[0]:
        print(-1)
        return
    moved = [False] * m
    time = 0
    moved_count = 0
    while moved_count < m:
        for i in range(n):
            for j in range(m):
                if not moved[j] and cranes[i] >= boxes[j]:
                    moved[j] = True
                    moved_count += 1
                    break
        time += 1
    print(time)
if __name__ == "__main__":
    solve()
