def solution():
    # 19x19 바둑판 상태 입력
    board = []
    for _ in range(19):
        board.append(list(map(int, input().split())))
    
    # 8방향 탐색을 위한 델타 값 (우, 우하, 하, 좌하, 좌, 좌상, 상, 우상)
    dx = [0, 1, 1, 1, 0, -1, -1, -1]
    dy = [1, 1, 0, -1, -1, -1, 0, 1]
    
    # 승리 여부 및 승리한 돌의 위치
    winner = 0
    win_row, win_col = 0, 0
    
    # 바둑판 전체 탐색
    for i in range(19):
        for j in range(19):
            # 바둑알이 있는 경우
            if board[i][j] != 0:
                stone = board[i][j]  # 현재 돌의 색깔
                
                # 8방향으로 탐색
                for dir in range(8):
                    count = 1  # 연속된 돌의 개수
                    ni, nj = i + dx[dir], j + dy[dir]
                    
                    # 같은 색 돌이 연속으로 있는지 확인
                    while 0 <= ni < 19 and 0 <= nj < 19 and board[ni][nj] == stone:
                        count += 1
                        ni += dx[dir]
                        nj += dy[dir]
                    
                    # 정확히 5개의 돌이 연속으로 있는지 확인
                    if count == 5:
                        # 6개 이상이 연속되는지 확인 (반대 방향)
                        oi, oj = i - dx[dir], j - dy[dir]
                        if oi < 0 or oi >= 19 or oj < 0 or oj >= 19 or board[oi][oj] != stone:
                            # 승리 조건 만족
                            winner = stone
                            # 가장 왼쪽 또는 가장 위에 있는 돌의 위치 찾기
                            if dir in [0, 1, 2, 7]:  # 우, 우하, 하, 우상
                                win_row, win_col = i + 1, j + 1  # 1-indexed로 변환
                            elif dir == 3:  # 좌하
                                win_row, win_col = i + 4 + 1, j - 4 + 1
                            elif dir == 4:  # 좌
                                win_row, win_col = i + 1, j - 4 + 1
                            elif dir == 5:  # 좌상
                                win_row, win_col = i - 4 + 1, j - 4 + 1
                            elif dir == 6:  # 상
                                win_row, win_col = i - 4 + 1, j + 1
    
    # 결과 출력
    print(winner)
    if winner != 0:
        print(win_row, win_col)
    
    return ""

if __name__ == "__main__":
    solution()
