#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
* 백준 17073 - 나무 위의 빗물
* 
* 문제 발상:
* 1. 트리에서 물이 루트부터 리프 노드까지 흘러내리는 문제
* 2. 핵심 아이디어:
*    - 물은 항상 아래쪽(자식 노드 방향)으로만 흐름
*    - 각 노드에서 물이 자식들에게 균등하게 분배됨
*    - 최종적으로 모든 물은 리프 노드에 도달
* 3. 리프 노드: 자식이 없는 노드 (루트 제외)
* 4. 물의 분배 원리:
*    - 루트에서 시작한 물 W가 각 리프까지 도달하는 경로를 생각
*    - 각 경로에서 물이 분할되는 비율을 계산
*    - 결과적으로 모든 리프 노드에 동일한 양의 물이 도달
* 5. 수학적 해결: 전체 물의 양 W를 리프 노드의 개수로 나눈 값
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    double W;
    cin >> N >> W;
    
    vector<int> degree(N + 1, 0);  // 각 노드의 차수
    
    // 트리의 간선 정보 입력
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        degree[U]++;
        degree[V]++;
    }
    
    // 리프 노드의 개수 계산
    int leaf_count = 0;
    for (int i = 1; i <= N; i++) {
        // 1번 노드(루트)가 아니면서 차수가 1인 노드가 리프 노드
        if (i != 1 && degree[i] == 1) {
            leaf_count++;
        }
    }
    
    // 특별한 경우: 트리가 노드 1개만 있는 경우
    if (N == 1) {
        leaf_count = 1;
    }
    
    // 각 리프 노드에 도달하는 물의 양 = 전체 물의 양 / 리프 노드 개수
    double result = W / leaf_count;
    
    // 결과 출력 (소수점 이하 자릿수 조정)
    cout << fixed << setprecision(10) << result << '\n';
    
    return 0;
}
