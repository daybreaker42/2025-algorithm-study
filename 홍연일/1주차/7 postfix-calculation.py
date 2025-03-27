# 07_1935.py - Postfix Evaluation

def main():
    n = int(input())
    expression = input().strip()
    values = [float(input()) for _ in range(n)]
    
    # Solving
    stack = []
    for char in expression:
        if char.isalpha():
            stack.append(values[ord(char) - ord('A')])
        else:  # Operator
            b = stack.pop()
            a = stack.pop()
            
            if char == '+':
                stack.append(a + b)
            elif char == '-':
                stack.append(a - b)
            elif char == '*':
                stack.append(a * b)
            elif char == '/':
                stack.append(a / b)
    
    # Output result with 2 decimal places
    print(f"{stack[0]:.2f}")

if __name__ == "__main__":
    main()

# comment - 250208
# - Postfix notation evaluation
# - When encountering a letter, push its value to stack
# - When encountering an operator, pop two values, perform operation, and push result back
# - Be careful about overflow and division by zero
