# 00_18258.py - Queue Implementation

from collections import deque

def main():
    n = int(input())
    queue = deque()
    
    for _ in range(n):
        command = input().split()
        
        if command[0] == "push":
            queue.append(int(command[1]))
        elif command[0] == "pop":
            print(queue.popleft() if queue else -1)
        elif command[0] == "size":
            print(len(queue))
        elif command[0] == "empty":
            print(1 if not queue else 0)
        elif command[0] == "front":
            print(queue[0] if queue else -1)
        elif command[0] == "back":
            print(queue[-1] if queue else -1)

if __name__ == "__main__":
    main()
