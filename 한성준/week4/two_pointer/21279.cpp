#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 광물 정보
struct Mineral {
    int x, y, v, c;  // x좌표, y좌표, 가치, 무게
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    // 광물 정보 입력
    vector<Mineral> minerals(N);
    for (int i = 0; i < N; i++) {
        cin >> minerals[i].x >> minerals[i].y >> minerals[i].v >> minerals[i].c;
    }
    
    // x좌표 기준 오름차순 정렬
    sort(minerals.begin(), minerals.end(), [](const Mineral& a, const Mineral& b) {
        return a.x < b.x;
    });
    
    // y좌표별 광물 정보 (무게 합, 가치 합)
    vector<pair<long long, long long>> y_info(100001, {0, 0});
    
    long long answer = 0;
    long long total_value = 0;
    long long total_cost = 0;
    
    int right = 0;  // x좌표 포인터
    
    // y좌표를 감소시키며 직사각형 영역 조정
    for (int y = 100000; y >= 0; y--) {
        // y좌표가 y+1인 광물들 제거
        total_value -= y_info[y+1].second;
        total_cost -= y_info[y+1].first;
        
        // x좌표를 증가시키며 광물 추가
        while (right < N) {
            Mineral& m = minerals[right];
            
            // 현재 광물의 y좌표가 현재 y 이하인지 확인
            if (m.y <= y) {
                // 무게 제한 확인
                if (total_cost + m.c <= C) {
                    total_cost += m.c;
                    total_value += m.v;
                    y_info[m.y].first += m.c;   // 해당 y좌표의 무게 합 갱신
                    y_info[m.y].second += m.v;  // 해당 y좌표의 가치 합 갱신
                    right++;
                } else {
                    break;  // 무게 제한 초과
                }
            } else {
                right++;  // y좌표가 범위를 벗어나면 다음 광물로
            }
        }
        
        // 최대 가치 갱신
        answer = max(answer, total_value);
    }
    
    cout << answer << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 좌표 범위는 0 이상 100,000 이하
const int MAX_COORD = 100001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    // 같은 y 좌표를 가진 광물들을 x 좌표별로 저장
    vector<vector<pair<int, int>>> minerals_by_y(MAX_COORD); // (x, index)
    
    vector<int> values(N); // 광물의 가치
    vector<int> costs(N);  // 광물의 무게
    
    for (int i = 0; i < N; i++) {
        int x, y, v, c;
        cin >> x >> y >> v >> c;
        minerals_by_y[y].push_back({x, i});
        values[i] = v;
        costs[i] = c;
    }
    
    long long answer = 0;
    long long current_value = 0;
    long long current_cost = 0;
    
    // 포함된 광물들
    vector<bool> included(N, false);
    
    // x 좌표 포인터
    int max_x = 0;
    
    // y 좌표를 높은 것부터 낮은 것까지 검사
    for (int y = MAX_COORD - 1; y >= 0; y--) {
        // y+1 좌표의 광물 제거 (이전 단계에서 포함됐던 것들)
        for (auto& [x, idx] : minerals_by_y[y + 1]) {
            if (included[idx]) {
                current_value -= values[idx];
                current_cost -= costs[idx];
                included[idx] = false;
            }
        }
        
        // x 좌표를 증가시키며 광물 추가 시도
        while (max_x < MAX_COORD) {
            bool can_extend = true;
            
            // max_x+1 위치의 광물들 확인
            for (int i = 0; i <= y; i++) {
                for (auto& [x, idx] : minerals_by_y[i]) {
                    if (x == max_x + 1 && !included[idx]) {
                        // 무게 제한 초과하는지 확인
                        if (current_cost + costs[idx] > C) {
                            can_extend = false;
                            break;
                        }
                        
                        // 광물 추가
                        current_value += values[idx];
                        current_cost += costs[idx];
                        included[idx] = true;
                    }
                }
                if (!can_extend) break;
            }
            
            if (!can_extend) break;
            max_x++;
        }
        
        answer = max(answer, current_value);
    }
    
    cout << answer << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mineral {
    int x, y, v, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    vector<Mineral> minerals(N);
    for (int i = 0; i < N; i++) {
        cin >> minerals[i].x >> minerals[i].y >> minerals[i].v >> minerals[i].c;
    }
    
    // y 좌표별로 광물 그룹화
    vector<vector<int>> yToMinerals(100001);
    for (int i = 0; i < N; i++) {
        yToMinerals[minerals[i].y].push_back(i);
    }
    
    // x 좌표 기준으로 정렬
    vector<pair<int, int>> xSorted(N);
    for (int i = 0; i < N; i++) {
        xSorted[i] = {minerals[i].x, i};
    }
    sort(xSorted.begin(), xSorted.end());
    
    long long answer = 0;
    
    // y를 줄여가며 탐색
    for (int y = 100000; y >= 0; y--) {
        vector<pair<int, pair<long long, long long>>> events; // {x위치, {가치 변화, 무게 변화}}
        
        // y 높이에 있는 광물들 추가
        for (int idx : yToMinerals[y]) {
            events.push_back({minerals[idx].x, {minerals[idx].v, minerals[idx].c}});
        }
        
        // 이벤트 x 좌표 기준 정렬
        sort(events.begin(), events.end());
        
        long long totalValue = 0;
        long long totalCost = 0;
        
        // x를 증가시키며 광물 추가
        for (auto [x, change] : events) {
            // 무게 제한을 초과하면 종료
            if (totalCost + change.second > C) {
                break;
            }
            
            totalValue += change.first;
            totalCost += change.second;
        }
        
        answer = max(answer, totalValue);
    }
    
    cout << answer << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mineral {
    int x, y, v, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    vector<Mineral> minerals(N);
    for (int i = 0; i < N; i++) {
        cin >> minerals[i].x >> minerals[i].y >> minerals[i].v >> minerals[i].c;
    }
    
    // x좌표별로 광물 모으기
    vector<vector<int>> byX(100001);
    for (int i = 0; i < N; i++) {
        byX[minerals[i].x].push_back(i);
    }
    
    // y좌표별로 광물 모으기
    vector<vector<int>> byY(100001);
    for (int i = 0; i < N; i++) {
        byY[minerals[i].y].push_back(i);
    }
    
    long long answer = 0;
    long long totalValue = 0;
    long long totalCost = 0;
    
    // 현재 직사각형에 포함된 광물들
    vector<bool> included(N, false);
    
    int maxX = 0;
    
    // y좌표를 감소시키며 탐색
    for (int y = 100000; y >= 0; y--) {
        // y가 y인 광물 제거
        for (int idx : byY[y + 1]) {
            if (included[idx]) {
                totalValue -= minerals[idx].v;
                totalCost -= minerals[idx].c;
                included[idx] = false;
            }
        }
        
        // x좌표를 증가시키며 광물 추가
        while (maxX <= 100000) {
            bool canAdd = true;
            long long newCost = totalCost;
            
            // maxX 좌표의 광물들 중 y 이하의 광물만 추가 시도
            for (int idx : byX[maxX]) {
                if (minerals[idx].y <= y) {
                    newCost += minerals[idx].c;
                }
            }
            
            // 무게 제한 초과시 중단
            if (newCost > C) {
                canAdd = false;
            }
            
            if (!canAdd) break;
            
            // 실제로 광물 추가
            for (int idx : byX[maxX]) {
                if (minerals[idx].y <= y) {
                    totalValue += minerals[idx].v;
                    totalCost += minerals[idx].c;
                    included[idx] = true;
                }
            }
            
            maxX++;
        }
        
        answer = max(answer, totalValue);
    }
    
    cout << answer << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    // 광물 정보를 (x, y) 좌표별로 저장
    vector<vector<pair<int, int>>> xy(100001);
    
    // y 좌표 기준으로 저장
    vector<vector<pair<int, int>>> yx(100001);
    
    for (int i = 0; i < N; i++) {
        int x, y, v, c;
        cin >> x >> y >> v >> c;
        xy[x].push_back({y, i}); // x 좌표에 (y, 인덱스) 저장
        yx[y].push_back({x, i}); // y 좌표에 (x, 인덱스) 저장
    }
    
    vector<int> value(N); // 각 광물의 가치
    vector<int> cost(N);  // 각 광물의 무게
    
    for (int i = 0; i < N; i++) {
        cin >> value[i] >> cost[i];
    }
    
    long long result = 0;
    long long sumValue = 0;
    long long sumCost = 0;
    
    vector<bool> included(N, false); // 포함된 광물 표시
    
    int currentX = 0;
    
    // y 좌표를 줄여가며 탐색
    for (int y = 100000; y >= 0; y--) {
        // y 좌표가 현재값인 광물들 제거
        for (auto& [x, idx] : yx[y]) {
            if (included[idx]) {
                sumValue -= value[idx];
                sumCost -= cost[idx];
                included[idx] = false;
            }
        }
        
        // x 좌표를 늘려가며 광물 추가
        while (currentX <= 100000 && sumCost <= C) {
            for (auto& [yi, idx] : xy[currentX]) {
                if (yi <= y && !included[idx]) {
                    if (sumCost + cost[idx] <= C) {
                        sumValue += value[idx];
                        sumCost += cost[idx];
                        included[idx] = true;
                    }
                }
            }
            currentX++;
        }
        
        result = max(result, sumValue);
    }
    
    cout << result << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mineral {
    int x, y, v, c; // x, y 좌표, 가치(v), 무게(c)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C; // N: 광물의 개수, C: 무게 제한
    cin >> N >> C;
    
    vector<Mineral> minerals(N);
    for (int i = 0; i < N; i++) {
        cin >> minerals[i].x >> minerals[i].y >> minerals[i].v >> minerals[i].c;
    }
    
    // x좌표 기준 오름차순 정렬
    sort(minerals.begin(), minerals.end(), [](const Mineral& a, const Mineral& b) {
        return a.x < b.x;
    });
    
    // y좌표별 광물 정보 (가치 합, 무게 합)
    vector<pair<long long, long long>> yInfo(100001, {0, 0});
    
    long long maxValue = 0;
    long long currentValue = 0;
    long long currentWeight = 0;
    
    int xPtr = 0; // x 포인터
    int maxY = 0; // 고려할 최대 y 좌표
    
    for (int y = 100000; y >= 0; y--) {
        // y 좌표가 현재 y 이하인 광물들 추가 (x 좌표 순서대로)
        while (xPtr < N && currentWeight <= C) {
            if (minerals[xPtr].y <= y) {
                currentValue += minerals[xPtr].v;
                currentWeight += minerals[xPtr].c;
                yInfo[minerals[xPtr].y].first += minerals[xPtr].v;
                yInfo[minerals[xPtr].y].second += minerals[xPtr].c;
                maxY = max(maxY, minerals[xPtr].y);
            }
            xPtr++;
            
            // 무게 제한 초과 시 마지막 광물 제거
            if (currentWeight > C) {
                xPtr--;
                currentValue -= minerals[xPtr].v;
                currentWeight -= minerals[xPtr].c;
                yInfo[minerals[xPtr].y].first -= minerals[xPtr].v;
                yInfo[minerals[xPtr].y].second -= minerals[xPtr].c;
                break;
            }
        }
        
        // 최대 가치 갱신
        maxValue = max(maxValue, currentValue);
        
        // y 좌표가 다음 y값인 광물들 제거
        if (y > 0) {
            currentValue -= yInfo[y].first;
            currentWeight -= yInfo[y].second;
        }
    }
    
    cout << maxValue << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mineral {
    int x, y, v, c; // x, y 좌표, 가치(v), 무게(c)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C; // N: 광물의 개수, C: 무게 제한
    cin >> N >> C;
    
    // 각 좌표는 0~100,000 범위
    const int MAX_COORD = 100001;
    
    vector<vector<pair<int, int>>> byX(MAX_COORD); // x좌표별 (y, v, c) 정보
    
    for (int i = 0; i < N; i++) {
        int x, y, v, c;
        cin >> x >> y >> v >> c;
        byX[x].push_back({y, v, c}); // x좌표에 해당하는 광물 정보 저장
    }
    
    long long maxValue = 0; // 최대 가치
    long long currentValue = 0; // 현재 가치
    long long currentWeight = 0; // 현재 무게
    
    // y좌표별로 포함된 광물의 가치와 무게 합계
    vector<pair<long long, long long>> byY(MAX_COORD, {0, 0}); // (가치 합, 무게 합)
    
    int maxY = 0; // 현재까지 고려한 최대 y좌표
    
    // x좌표를 증가시키며 탐색
    for (int x = 0; x < MAX_COORD; x++) {
        // 현재 x좌표의 광물들 처리
        for (auto& [y, v, c] : byX[x]) {
            byY[y].first += v;  // 가치 추가
            byY[y].second += c; // 무게 추가
            maxY = max(maxY, y);
        }
        
        // y좌표를 감소시키며 최적의 y경계 찾기
        currentValue = 0;
        currentWeight = A SEARCH GAL 0;
        
        for (int y = 0; y <= maxY; y++) {
            currentValue += byY[y].first;
            currentWeight += byY[y].second;
            
            // 무게 제한 초과시 광물 제거
            if (currentWeight > C) {
                currentValue = 0;
                currentWeight = 0;
                break;
            }
        }
        
        // 최대 가치 갱신
        maxValue = max(maxValue, currentValue);
    }
    
    cout << maxValue << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 광물 정보를 담는 구조체
struct Mineral {
    int x, y, v, c; // x, y 좌표, 가치(v), 무게(c)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C; // N: 광물의 개수, C: 무게 제한
    cin >> N >> C;
    
    vector<Mineral> minerals(N);
    for (int i = 0; i < N; i++) {
        cin >> minerals[i].x >> minerals[i].y >> minerals[i].v >> minerals[i].c;
    }
    
    // x 좌표 기준으로 오름차순 정렬
    sort(minerals.begin(), minerals.end(), [](const Mineral& a, const Mineral& b) {
        return a.x < b.x;
    });
    
    // y 좌표 기준으로 정렬된 광물들의 인덱스
    vector<int> ySorted(N);
    for (int i = 0; i < N; i++) {
        ySorted[i] = i;
    }
    
    sort(ySorted.begin(), ySorted.end(), [&](int a, int b) {
        return minerals[a].y < minerals[b].y;
    });
    
    long long maxValue = 0; // 최대 가치
    long long currentValue = 0; // 현재 가치
    long long currentWeight = 0; // 현재 무게
    
    int right = 0; // x 좌표 기준 오른쪽 포인터
    vector<bool> included(N, false); // 현재 영역에 포함된 광물
    
    // y 좌표를 줄여가며 탐색
    for (int yIdx = N - 1; yIdx >= 0; yIdx--) {
        int currentY = minerals[ySorted[yIdx]].y;
        
        // 현재 y 이하인 광물들 중 x 범위를 확장하며 탐색
        while (right < N && currentWeight + minerals[right].c <= C) {
            // 이미 포함된 광물이 아니고, y 좌표가 currentY 이하인 경우만 추가
            if (!included[right] && minerals[right].y <= currentY) {
                currentValue += minerals[right].v;
                currentWeight += minerals[right].c;
                included[right] = true;
            }
            right++;
        }
        
        // y좌표가 currentY인 광물들을 추가
        for (int i = 0; i < N; i++) {
            if (!included[i] && minerals[i].y <= currentY && minerals[i].x < minerals[right-1].x) {
                if (currentWeight + minerals[i].c <= C) {
                    currentValue += minerals[i].v;
                    currentWeight += minerals[i].c;
                    included[i] = true;
                } else {
                    break;
                }
            }
        }
        
        // 최대 가치 갱신
        maxValue = max(maxValue, currentValue);
        
        // y좌표가 currentY인 광물들 제거
        for (int i = 0; i < N; i++) {
            if (included[i] && minerals[i].y == currentY) {
                currentValue -= minerals[i].v;
                currentWeight -= minerals[i].c;
                included[i] = false;
            }
        }
    }
    
    cout << maxValue << '\n';
    
    return 0;
}
