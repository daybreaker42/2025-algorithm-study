# 11_2504.py - Bracket Value

def calculate_value(expression):
    stack = []
    
    # Define bracket pairs and values
    pairs = {'(': ')', '[': ']'}
    values = {'(': 2, '[': 3}
    
    for char in expression:
        if char in '([':  # Opening bracket
            stack.append(char)
        else:  # Closing bracket
            if not stack:  # No matching opening bracket
                return 0
                
            if char == ')' and stack[-1] == '(' or char == ']' and stack[-1] == '[':
                # Direct pair
                if len(stack) == 1 or stack[-2] not in '([':
                    # Replace with value
                    stack.pop()
                    stack.append(values['(' if char == ')' else '['])
                else:
                    # Calculate inner value
                    val = stack.pop()
                    opening = stack.pop()
                    stack.append(val * values[opening])
            else:
                # Mismatched brackets
                return 0
                
            # Combine consecutive numbers
            while len(stack) >= 2 and isinstance(stack[-1], int) and isinstance(stack[-2], int):
                val1 = stack.pop()
                val2 = stack.pop()
                stack.append(val1 + val2)
    
    # Check if there's exactly one value left and no brackets
    if len(stack) == 1 and isinstance(stack[0], int):
        return stack[0]
    return 0

def main():
    expression = input().strip()
    print(calculate_value(expression))

if __name__ == "__main__":
    main()

# comment - 250215
# Caution:
# - String length <= 30 -> result could be up to 3^30 ≈ 2*10^14 -> beyond int range
# 
# Algorithm:
# 1. For ( or [ push to stack
# 2. When ) or ] appears, check for matching bracket and calculate value:
#    - If direct pair with no inner content, use bracket value (2 or 3)
#    - If pair contains inner value, multiply inner value by bracket value
# 3. Return 0 for incomplete or invalid expressions
