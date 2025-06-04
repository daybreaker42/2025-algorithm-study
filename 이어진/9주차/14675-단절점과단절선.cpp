#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 14675 - 단절점과 단절선
* 
* 문제 발상:
* 1. 트리에서의 단절점과 단절선의 특성을 이용한 문제
* 2. 트리의 중요한 성질:
*    - 트리는 이미 연결되어 있고 사이클이 없는 그래프
*    - 트리에서 임의의 간선을 제거하면 그래프는 두 개의 연결 성분으로 분리됨
*    - 트리에서 리프 노드(차수가 1인 노드)가 아닌 노드를 제거하면 그래프가 분리됨
* 3. 단절선: 트리의 모든 간선은 단절선 (제거 시 연결 성분이 분리되므로)
* 4. 단절점: 리프 노드가 아닌 모든 노드는 단절점 (차수가 2 이상인 노드)
* 5. 예외: 트리가 노드 2개로만 이루어진 경우, 두 노드 모두 리프이지만 단절점
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> degree(N + 1, 0);  // 각 노드의 차수
    
    // 트리의 간선 정보 입력 및 차수 계산
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    
    int q;
    cin >> q;
    
    // 질의 처리
    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        
        if (t == 1) {
            // k번 노드가 단절점인지 확인
            // 리프 노드(차수가 1)가 아니면 단절점
            // 예외: N=2인 경우 모든 노드가 단절점
            if (N == 2 || degree[k] >= 2) {
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
        } else {
            // k번 간선이 단절선인지 확인
            // 트리의 모든 간선은 단절선
            cout << "yes" << '\n';
        }
    }
    
    return 0;
}
