import sys
input = sys.stdin.read
def solve():
    data = input().split()
    N, K = int(data[0]), int(data[1])
    number = data[2]
    result = []
    remove_count = 0
    for i in range(N):
        while result and result[-1] < number[i] and remove_count < K:
            result.pop()
            remove_count += 1
        result.append(number[i])
    while remove_count < K:
        result.pop()
        remove_count += 1
    print("".join(result))
if __name__ == "__main__":
    solve()
