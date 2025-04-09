import math

def solution():
    N, M = map(int, input().split())
    
    table = []
    for _ in range(N):
        table.append(input().strip())
    
    def is_perfect_square(num):
        if num < 0:
            return False
        sqrt_num = int(math.sqrt(num))
        return sqrt_num * sqrt_num == num
    
    max_perfect_square = -1
    
    # 시작 위치와 공차를 모두 시도
    for start_row in range(N):
        for start_col in range(M):
            for row_diff in range(-N+1, N):
                for col_diff in range(-M+1, M):
                    # 행과 열의 공차가 둘 다 0인 경우는 건너뛰기 (한 자리수만 선택)
                    if row_diff == 0 and col_diff == 0:
                        # 한 자리 숫자의 경우 제곱수인지 확인
                        num = int(table[start_row][start_col])
                        if is_perfect_square(num):
                            max_perfect_square = max(max_perfect_square, num)
                        continue
                    
                    num_str = ""
                    row, col = start_row, start_col
                    
                    # 표 범위 내에서 등차수열을 따라 숫자 이어붙이기
                    while 0 <= row < N and 0 <= col < M:
                        num_str += table[row][col]
                        row += row_diff
                        col += col_diff
                        
                        # 현재까지의 숫자가 제곱수인지 확인
                        if num_str:
                            num = int(num_str)
                            if is_perfect_square(num):
                                max_perfect_square = max(max_perfect_square, num)
    
    return str(max_perfect_square)

if __name__ == "__main__":
    print(solution())
