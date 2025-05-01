def main():
    n, x = map(int, input().split())
    visitors = list(map(int, input().split()))
    
    if x > n:
        print("SAD")
        return
    
    current_visitors = sum(visitors[:x])
    max_visitors = current_visitors
    count = 1
    
    for i in range(x, n):
        current_visitors -= visitors[i - x]
        current_visitors += visitors[i]
        
        if current_visitors > max_visitors:
            max_visitors = current_visitors
            count = 1
        elif current_visitors == max_visitors:
            count += 1
    
    if max_visitors == 0:
        print("SAD")
    else:
        print(max_visitors)
        print(count)

if __name__ == "__main__":
    main()
