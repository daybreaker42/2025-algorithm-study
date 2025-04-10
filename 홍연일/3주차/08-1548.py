def solution():
    # 세 수가 삼각관계를 만족하는지 확인하는 함수
    def is_triangle(a, b, c):
        return (a + b > c) and (a + c > b) and (b + c > a)
    
    # 주어진 수열이 삼각 수열인지 확인하는 함수
    def is_triangle_sequence(seq):
        n = len(seq)
        if n < 3:
            return True  # 원소가 3개 미만이면 무조건 성립
        
        # 모든 가능한 세 원소 조합을 확인
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if not is_triangle(seq[i], seq[j], seq[k]):
                        return False  # 삼각관계를 만족하지 않는 세 수가 있으면 삼각 수열이 아님
        return True  # 모든 세 수 조합이 삼각관계를 만족하면 삼각 수열임
    
    # 비트마스킹을 이용한 모든 부분 수열 검사
    def find_max_triangle_subsequence(arr):
        n = len(arr)
        max_length = 0
        
        # 2^n개의 모든 부분집합을 검사
        for mask in range(1, 1 << n):
            subsequence = []
            
            # 현재 마스크에 대응되는 부분 수열 생성
            for i in range(n):
                if mask & (1 << i):
                    subsequence.append(arr[i])
            
            # 생성된 부분 수열이 삼각 수열인지 확인
            if is_triangle_sequence(subsequence):
                max_length = max(max_length, len(subsequence))
        
        return max_length
    
    n = int(input())
    arr = list(map(int, input().split()))
    
    # 길이가 1 또는 2인 수열은 항상 삼각 수열
    if n <= 2:
        return str(n)
    
    # 모든 원소가 같은 값인지 확인
    if all(x == arr[0] for x in arr):
        return str(n)  # 모든 원소가 같은 값이면 항상 삼각 수열
    
    result = find_max_triangle_subsequence(arr)
    return str(result)

if __name__ == "__main__":
    print(solution())
