import sys
input = sys.stdin.read
def solve():
    expression = input().strip()
    result = 0
    num = ""
    is_minus = False
    for i in range(len(expression)+1):
        if i == len(expression) or expression[i] in "+-":
            if num:
                if is_minus:
                    result -= int(num)
                else:
                    result += int(num)
                num = ""
            if i < len(expression) and expression[i] == '-':
                is_minus = True
        else:
            num += expression[i]
    print(result)
if __name__ == "__main__":
    solve()
