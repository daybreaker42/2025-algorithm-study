def solution():
    N = int(input())
    garden = []
    for _ in range(N):
        garden.append(list(map(int, input().split())))
    
    # 꽃이 차지하는 위치들 반환 (중앙 + 상하좌우)
    dx = [0, -1, 1, 0, 0]
    dy = [0, 0, 0, -1, 1]
    
    # 가능한 꽃 위치 미리 계산
    possible_positions = []
    costs = {}
    
    for i in range(1, N-1):
        for j in range(1, N-1):
            positions = []
            cost = 0
            for k in range(5):
                nx, ny = i + dx[k], j + dy[k]
                positions.append((nx, ny))
                cost += garden[nx][ny]
            possible_positions.append((i, j))
            costs[(i, j)] = (positions, cost)
    
    min_cost = float('inf')
    
    # 세 개의 꽃 위치 선택
    for i in range(len(possible_positions)):
        for j in range(i+1, len(possible_positions)):
            for k in range(j+1, len(possible_positions)):
                pos1 = possible_positions[i]
                pos2 = possible_positions[j]
                pos3 = possible_positions[k]
                
                positions1, cost1 = costs[pos1]
                positions2, cost2 = costs[pos2]
                positions3, cost3 = costs[pos3]
                
                # 겹치는 위치가 있는지 확인
                all_positions = positions1 + positions2 + positions3
                if len(all_positions) == len(set(all_positions)):
                    total_cost = cost1 + cost2 + cost3
                    min_cost = min(min_cost, total_cost)
    
    return min_cost

if __name__ == "__main__":
    print(solution())
