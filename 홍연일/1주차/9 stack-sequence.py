# 09_1874.py - Stack Sequence

def main():
    n = int(input())
    sequence = [int(input()) for _ in range(n)]
    
    # Solving
    stack = []
    operations = []
    current = 1
    possible = True
    
    for num in sequence:
        # Push until we reach the desired number
        while current <= num:
            stack.append(current)
            operations.append('+')
            current += 1
        
        # Check if we can pop the desired number
        if stack and stack[-1] == num:
            stack.pop()
            operations.append('-')
        else:
            possible = False
            break
    
    # Output
    if possible:
        for op in operations:
            print(op)
    else:
        print("NO")

if __name__ == "__main__":
    main()

# comment - 250208
# - Fill stack in order and pop when needed
# - Record operations as they happen
# - If stack is not empty at the end or if sequence can't be formed, output "NO"
#
# Failure case:
# - When the number at the top of the stack doesn't match the current required number
#   and numbers must be pushed/popped in a specific order
