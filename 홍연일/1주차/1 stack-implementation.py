# 01_10828.py - Stack Implementation

class Stack:
    def __init__(self):
        self.stack = []
        
    def push(self, x):
        self.stack.append(x)
        
    def pop(self):
        if not self.empty():
            return self.stack.pop()
        return -1
        
    def size(self):
        return len(self.stack)
        
    def empty(self):
        return 1 if len(self.stack) == 0 else 0
        
    def top(self):
        if not self.empty():
            return self.stack[-1]
        return -1

def main():
    n = int(input())
    s = Stack()
    
    for _ in range(n):
        command = input().split()
        
        if command[0] == "push":
            s.push(int(command[1]))
        elif command[0] == "pop":
            print(s.pop())
        elif command[0] == "size":
            print(s.size())
        elif command[0] == "empty":
            print(s.empty())
        elif command[0] == "top":
            print(s.top())

if __name__ == "__main__":
    main()

# comment - 250208
# - Implement stack operations exactly as they behave
