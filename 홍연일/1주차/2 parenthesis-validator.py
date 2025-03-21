# 02_9012.py - Parenthesis Validator

def is_valid_parenthesis(string):
    stack = []
    
    for char in string:
        if char == '(':
            stack.append(char)
        else:  # char is ')'
            if stack:
                stack.pop()
            else:
                return False
    
    return len(stack) == 0

def main():
    t = int(input())
    
    for _ in range(t):
        string = input().strip()
        if is_valid_parenthesis(string):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# comment - 250207
# - When a opening parenthesis appears, push to stack, when closing, pop one
# - If we need to pop but stack is empty, or if stack is not empty after checking all characters, it's not a VPS
