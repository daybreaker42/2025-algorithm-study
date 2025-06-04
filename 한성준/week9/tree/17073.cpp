#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int main() {
    int n, w;    // n은 노드의 개수, w는 물의 양
    cin >> n >> w; // 노드의 개수와 물의 양 입력

    vector<int> degree(n + 1, 0); // 각 노드의 차수 저장 (1-based indexing)
    // 간선 정보 입력 및 각 노드의 차수 계산
    for (int i = 0; i < n - 1; ++i) {
        int u, v;    // 간선 (u, v)
        cin >> u >> v; // 간선 정보 입력
        degree[u]++; // u의 차수 증가
        degree[v]++; // v의 차수 증가
    }

    int leafCount = 0; // 리프 노드의 개수
    // 리프 노드 개수 계산
    for (int i = 2; i <= n; ++i) {
        if (degree[i] == 1) { // 차수가 1이면 리프 노드
            leafCount++;       // 리프 노드 개수 증가
        }
    }

    // 노드가 하나인 경우
    if (n == 1) {
        cout << w << endl; // 물의 양 출력
    } else {
        cout.precision(10);                               // 소수점 정밀도 설정
        cout << fixed << (double)w / leafCount << endl; // 각 리프 노드에 분배될 물의 양 출력
    }

    return 0; // 프로그램 종료
}
