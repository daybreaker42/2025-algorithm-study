import sys
input = sys.stdin.read
def solve():
    data = list(map(int, input().split()))
    n = data[0]
    meetings = [(data[i], data[i+1]) for i in range(1, 2*n, 2)]
    meetings.sort(key=lambda x: (x[1], x[0]))
    count = 0
    end_time = 0
    for start, end in meetings:
        if start >= end_time:
            count += 1
            end_time = end
    print(count)
if __name__ == "__main__":
    solve()
