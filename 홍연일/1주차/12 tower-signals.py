# 12_2493.py - Tower Signals

def main():
    n = int(input())
    towers = list(map(int, input().split()))
    
    # Solving
    stack = []  # (height, position) pairs
    result = [0] * n
    
    for i in range(n):
        # Check if current tower can be seen by any previous towers
        while stack and stack[-1][0] < towers[i]:
            stack.pop()  # Remove towers that can't see beyond current tower
            
        # If there's a taller tower in stack, it can receive signal
        if stack:
            result[i] = stack[-1][1] + 1  # +1 because positions are 1-indexed
            
        # Add current tower to stack
        stack.append((towers[i], i))
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()

# comment 
# - Similar problem: 22866 Tower View
#
# Keep track of towers that can potentially receive signals:
# - If stack is empty, push current tower
# - If a tower is taller than towers on stack, pop until finding a taller tower
# - Record the position of the first taller tower as the receiver
