import sys

n, s = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))

start = 0
end = 0
ans = 100001
sum_num = num[0]

while start < n:
    if start == end and s < num[start]:
        ans = 1
        break
    elif s <= sum_num:
        ans = min(ans, end-start+1)
        sum_num -= num[start]
        start += 1
    else:
        end += 1
        if end == n:
            break
        sum_num += num[end]

if ans == 100001:
    print(0)
else:
    print(ans)
