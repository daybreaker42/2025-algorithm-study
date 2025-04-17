def main():
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    
    left = 0
    right = 0
    current_sum = 0
    min_length = n + 1
    
    while right < n:
        current_sum += a[right]
        
        while current_sum >= s:
            min_length = min(min_length, right - left + 1)
            current_sum -= a[left]
            left += 1
        
        right += 1
    
    if min_length > n:
        print(0)
    else:
        print(min_length)

if __name__ == "__main__":
    main()
