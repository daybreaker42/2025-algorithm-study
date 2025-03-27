# 15_1918.py - Infix to Postfix

def main():
    expression = input().strip()
    
    # Define operator precedence
    def precedence(op):
        if op in '+-':
            return 1
        if op in '*/':
            return 2
        return 0
    
    result = []
    stack = []
    
    for char in expression:
        # If operand, add to result
        if char.isalpha():
            result.append(char)
        
        # If opening parenthesis, push to stack
        elif char == '(':
            stack.append(char)
        
        # If closing parenthesis, pop until matching opening parenthesis
        elif char == ')':
            while stack and stack[-1] != '(':
                result.append(stack.pop())
            
            # Remove the '(' from stack
            if stack and stack[-1] == '(':
                stack.pop()
        
        # If operator
        else:
            # Pop operators with higher or equal precedence
            while stack and stack[-1] != '(' and precedence(stack[-1]) >= precedence(char):
                result.append(stack.pop())
            
            # Push current operator
            stack.append(char)
    
    # Pop any remaining operators
    while stack:
        result.append(stack.pop())
    
    print(''.join(result))

if __name__ == "__main__":
    main()

# comment
# Idea:
# - Use two stacks: one for operators and one for the result
# - Process each character based on type (operand, operator, parenthesis)
# - Apply operator precedence rules when deciding to pop or push
# - Handle parentheses specially
# - Build the postfix expression by appending to result
