# 03_1158.py - Josephus Problem

from collections import deque

def main():
    n, k = map(int, input().split())
    
    # Initialize
    q = deque(range(1, n+1))
    result = []
    
    # Solving
    count = 1
    while len(result) < n:
        person = q.popleft()
        if count % k == 0:
            result.append(person)
        else:
            q.append(person)
        count += 1
    
    # Output
    print("<" + ", ".join(map(str, result)) + ">")

if __name__ == "__main__":
    main()

# comment
# - Use a queue to keep rotating the array and remove the k-th element
# - Store removed elements in a separate result array
