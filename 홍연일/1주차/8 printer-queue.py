# 08_1966.py - Printer Queue

from collections import deque

def main():
    t = int(input())
    
    for _ in range(t):
        n, target_idx = map(int, input().split())
        priorities = list(map(int, input().split()))
        
        # Create queue of (priority, original_index)
        printer_queue = deque([(priority, idx) for idx, priority in enumerate(priorities)])
        
        # Sort priorities for checking
        sorted_priorities = sorted(priorities, reverse=True)
        
        count = 0
        priority_idx = 0
        
        while printer_queue:
            current = printer_queue.popleft()
            
            # If current document has highest priority
            if current[0] == sorted_priorities[priority_idx]:
                count += 1
                priority_idx += 1
                
                # Check if this is the target document
                if current[1] == target_idx:
                    print(count)
                    break
            else:
                # Put it back in queue
                printer_queue.append(current)
    
if __name__ == "__main__":
    main()

# comment 250208
# idea)
# 1. Create a sorted list of priorities for reference
# 2. Rotate queue until documents with highest priority are printed
# 3. Count prints until target document is printed
#
# Q) Why not just sort?
# A) When stable sorting, with priorities like 1 1 9 1 1 1 where m=2, 
#    stable sort would give 3, but the answer is 6 (the last position)
