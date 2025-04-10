def solution():
    # 8개의 가능한 연산(3개 행, 3개 열, 2개 대각선)
    operations = [
        [1,1,1,0,0,0,0,0,0],  # 첫 번째 행
        [0,0,0,1,1,1,0,0,0],  # 두 번째 행
        [0,0,0,0,0,0,1,1,1],  # 세 번째 행
        [1,0,0,1,0,0,1,0,0],  # 첫 번째 열
        [0,1,0,0,1,0,0,1,0],  # 두 번째 열
        [0,0,1,0,0,1,0,0,1],  # 세 번째 열
        [1,0,0,0,1,0,0,0,1],  # 주 대각선 (\)
        [0,0,1,0,1,0,1,0,0]   # 부 대각선 (/)
    ]
    
    def all_same(coins):
        return all(c == coins[0] for c in coins)
    
    def find_min_operations(coins):
        min_ops = -1
        
        # 모든 가능한 연산 조합 시도 (각 연산은 최대 한 번만 사용)
        for mask in range(1 << 8):
            temp_coins = coins.copy()
            ops_count = 0
            
            for i in range(8):
                if mask & (1 << i):
                    ops_count += 1
                    for j in range(9):
                        if operations[i][j]:
                            # 동전 뒤집기
                            temp_coins[j] = 'H' if temp_coins[j] == 'T' else 'T'
            
            # 모든 동전이 같은 면인지 확인
            if all_same(temp_coins):
                if min_ops == -1 or ops_count < min_ops:
                    min_ops = ops_count
        
        return min_ops
    
    T = int(input())
    results = []
    
    for _ in range(T):
        coins = []
        for _ in range(3):
            row = input().split()
            coins.extend(row)
        
        results.append(str(find_min_operations(coins)))
    
    return '\n'.join(results)

if __name__ == "__main__":
    print(solution())
