def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    left = 0
    right = 0
    max_length = 0
    odd_count = 0
    
    while right < n:
        if a[right] % 2 != 0:
            odd_count += 1
        
        while odd_count > k:
            if a[left] % 2 != 0:
                odd_count -= 1
            left += 1
        
        max_length = max(max_length, right - left + 1)
        right += 1
    
    print(max_length)

if __name__ == "__main__":
    main()
