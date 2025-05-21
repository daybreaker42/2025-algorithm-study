import sys
input = sys.stdin.read
def solve():
    s = input().strip()
    max_result = ""
    i = 0
    while i < len(s):
        if s[i] == 'M':
            j = i
            while j < len(s) and s[j] == 'M':
                j += 1
            if j == len(s):
                max_result += '1' * (j - i)
                break
            elif s[j] == 'K':
                max_result += '5' + '0' * (j - i)
                i = j
        else:
            max_result += '5'
        i += 1
    min_result = ""
    i = 0
    while i < len(s):
        if s[i] == 'M':
            j = i
            while j < len(s) and s[j] == 'M':
                j += 1
            min_result += '1' + '0' * (j - i - 1)
            i = j
        else:
            min_result += '5'
            i += 1
    print(max_result)
    print(min_result)
if __name__ == "__main__":
    solve()
