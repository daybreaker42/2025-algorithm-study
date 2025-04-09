def solution():
    S = input().strip()
    T = input().strip()
    
    # T에서 S로 가는 방식으로 풀이
    def can_transform(target, current):
        if target == current:
            return True
        
        if len(current) <= len(target):
            return False
        
        # 마지막 문자가 'A'인 경우: A를 제거하고 재귀 호출
        if current[-1] == 'A':
            if can_transform(target, current[:-1]):
                return True
        
        # 첫 번째 문자가 'B'인 경우: B를 제거하고 뒤집은 후 재귀 호출
        if current[0] == 'B':
            if can_transform(target, current[1:][::-1]):
                return True
                
        return False
    
    result = 1 if can_transform(S, T) else 0
    return str(result)

if __name__ == "__main__":
    print(solution())
