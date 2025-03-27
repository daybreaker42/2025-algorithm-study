# 14_2800.py - Bracket Removal

def main():
    expression = input()
    
    # 1. Find all bracket pairs
    stack = []
    pairs = []
    
    for i, char in enumerate(expression):
        if char == '(':
            stack.append(i)
        elif char == ')':
            pairs.append((stack.pop(), i))
    
    num_pairs = len(pairs)
    results = set()
    
    # 2. Generate all possible combinations (except removing all brackets)
    for mask in range(1, 1 << num_pairs):
        result = list(expression)
        
        # Apply the current mask
        for i in range(num_pairs):
            if mask & (1 << i):
                # Include this bracket pair
                continue
            else:
                # Remove this bracket pair
                left, right = pairs[i]
                result[left] = ''
                result[right] = ''
        
        results.add(''.join(result))
    
    # 3. Sort and print
    for result in sorted(results):
        print(result)

if __name__ == "__main__":
    main()

# comment 
# Idea:
# - First identify all matching bracket pairs
# - Generate all combinations of keeping/removing brackets (2^n - 1 combinations)
# - Use bitmasking to represent which brackets to keep
# - Sort results and remove duplicates using a set
#
# Note:
# - 'Different expressions' means no duplicates -> use a set to check
