#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int main() {
    int n;       // 노드의 개수
    cin >> n;    // 노드의 개수 입력

    vector<int> degree(n + 1, 0); // 각 노드의 차수 저장 (1-based indexing)
    // 간선 정보 입력 및 각 노드의 차수 계산
    for (int i = 0; i < n - 1; ++i) {
        int u, v;    // 간선 (u, v)
        cin >> u >> v; // 간선 정보 입력
        degree[u]++; // u의 차수 증가
        degree[v]++; // v의 차수 증가
    }

    int q;       // 질의의 개수
    cin >> q;    // 질의의 개수 입력

    // 각 질의에 대한 처리
    for (int i = 0; i < q; ++i) {
        int t, k;    // 질의 타입 t와 노드 k
        cin >> t >> k; // 질의 정보 입력

        // 질의 타입에 따른 처리
        if (t == 1) { // 단절점 질의
            // 차수가 2 이상이면 단절점
            if (degree[k] >= 2) {
                cout << "yes" << endl; // 단절점인 경우 "yes" 출력
            } else {
                cout << "no" << endl;  // 단절점이 아닌 경우 "no" 출력
            }
        } else {       // 단절선 질의
            cout << "yes" << endl; // 단절선은 항상 "yes" 출력 (문제 조건에 따라)
        }
    }

    return 0; // 프로그램 종료
}
