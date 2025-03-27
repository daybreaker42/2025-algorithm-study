# 04_2164.py - Card Game

from collections import deque

def main():
    n = int(input())
    
    # Initialize queue with cards 1 to n
    q = deque(range(1, n+1))
    discard = True
    
    # Process cards until only one remains
    while len(q) > 1:
        if discard:
            q.popleft()  # Discard the top card
        else:
            q.append(q.popleft())  # Move top card to bottom
        discard = not discard
    
    print(q[0])

if __name__ == "__main__":
    main()

# comment - 250207
# - Rule: Alternately discard top card and move top card to bottom
# - Repeat until only one card remains
