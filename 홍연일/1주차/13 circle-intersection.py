# 13_22942.py - Circle Intersection

def main():
    n = int(input())
    points = []
    
    # Process each circle
    for i in range(n):
        center, radius = map(int, input().split())
        left = center - radius
        right = center + radius
        
        # Check for duplicate points on x-axis
        for point, _, _ in points:
            if point == left or point == right:
                print("NO")
                return
                
        # Add start and end points
        points.append((left, i, 1))   # 1 = start point
        points.append((right, i, 2))  # 2 = end point
    
    # Sort points by x-coordinate
    points.sort()
    
    # Check for valid nesting using stack
    stack = []
    for _, circle_idx, status in points:
        if status == 1:  # Start point
            stack.append(circle_idx)
        else:  # End point
            if not stack or stack[-1] != circle_idx:
                # Either empty stack or mismatch - invalid
                print("NO")
                return
            stack.pop()
    
    print("YES")

if __name__ == "__main__":
    main()

# comment - 250214
# Conditions for non-intersecting circles on a line:
# 1. |c1 - c2| <= r1 + r2 
# 2. For nested circles (r2 > r1): c2 - r2 < c1 - r1 and c1 + r1 < c2 + r2
#
# Implementation approach:
# - Treat circle boundaries as parentheses: (circle start, circle end)
# - Check for valid nesting using a stack
# - If circles intersect, the nesting will be invalid
