def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    left = 0
    right = 0
    max_length = 0
    frequency = {}
    
    while right < n:
        frequency[a[right]] = frequency.get(a[right], 0) + 1
        
        while frequency[a[right]] > k:
            frequency[a[left]] -= 1
            left += 1
        
        max_length = max(max_length, right - left + 1)
        right += 1
    
    print(max_length)

if __name__ == "__main__":
    main()
