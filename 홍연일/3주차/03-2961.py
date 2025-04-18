def solution():
    N = int(input())
    
    ingredients = []
    for _ in range(N):
        sour, bitter = map(int, input().split())
        ingredients.append((sour, bitter))
    
    min_diff = float('inf')
    
    # 모든 부분집합 검사 (비트마스킹 사용)
    for i in range(1, 1 << N):  # 1부터 시작하여 빈 집합을 제외
        sour = 1  # 신맛(곱)
        bitter = 0  # 쓴맛(합)
        
        for j in range(N):
            if i & (1 << j):  # j번째 재료를 사용한다면
                sour *= ingredients[j][0]
                bitter += ingredients[j][1]
        
        # 신맛과 쓴맛의 차이 계산
        diff = abs(sour - bitter)
        min_diff = min(min_diff, diff)
    
    return min_diff

if __name__ == "__main__":
    print(solution())
