def main():
    n = int(input())
    solutions = list(map(int, input().split()))
    
    solutions.sort()
    
    min_sum = None
    result_left = solutions[0]
    result_right = solutions[n - 1]
    
    left = 0
    right = n - 1
    
    while left < right:
        current_sum = solutions[left] + solutions[right]
        
        if min_sum is None or abs(current_sum) < abs(min_sum):
            min_sum = current_sum
            result_left = solutions[left]
            result_right = solutions[right]
        
        if current_sum < 0:
            left += 1
        else:
            right -= 1
    
    print(result_left, result_right)

if __name__ == "__main__":
    main()
