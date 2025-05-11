import sys
input = sys.stdin.read
def solve():
    data = input().split()
    C = int(data[0])
    N = int(data[1])
    cities = []
    idx = 2
    for _ in range(N):
        cost = int(data[idx])
        customers = int(data[idx+1])
        cities.append((cost, customers))
        idx += 2
    MAX = float('inf')
    dp = [MAX] * (C + 101)
    dp[0] = 0
    for i in range(C + 1):
        if dp[i] == MAX:
            continue
        for cost, customers in cities:
            if dp[i + customers] > dp[i] + cost:
                dp[i + customers] = dp[i] + cost
    result = min(dp[C:])
    print(result)
if __name__ == "__main__":
    solve()
