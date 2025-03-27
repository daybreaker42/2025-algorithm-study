# 06_2346.py - Balloon Popping

from collections import deque

def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    
    # Create deque of (balloon_index, move_value) pairs
    dq = deque([(i+1, num) for i, num in enumerate(numbers)])
    result = []
    
    # Pop balloons one by one
    while dq:
        idx, move = dq.popleft()
        result.append(idx)
        
        if not dq:  # If no more balloons
            break
            
        if move > 0:
            # Move right (clockwise)
            # We already popped one, so move (move-1) times
            for _ in range(move-1):
                dq.append(dq.popleft())
        else:
            # Move left (counter-clockwise)
            for _ in range(abs(move)):
                dq.appendleft(dq.pop())
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()

# comment 250207 
# - Similar to Josephus problem
# - When moving right, we've already removed one element so we need to adjust by 1
