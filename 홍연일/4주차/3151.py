def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    arr.sort()
    count = 0
    
    for i in range(n - 2):
        left = i + 1
        right = n - 1
        target = -arr[i]
        
        while left < right:
            sum_val = arr[left] + arr[right]
            
            if sum_val == target:
                if arr[left] == arr[right]:
                    num_elements = right - left + 1
                    count += num_elements * (num_elements - 1) // 2
                    break
                else:
                    left_val = arr[left]
                    right_val = arr[right]
                    left_count = 0
                    right_count = 0
                    
                    while left < right and arr[left] == left_val:
                        left += 1
                        left_count += 1
                    
                    while left < right and arr[right] == right_val:
                        right -= 1
                        right_count += 1
                    
                    count += left_count * right_count
            elif sum_val < target:
                left += 1
            else:
                right -= 1
    
    print(count)

if __name__ == "__main__":
    main()
