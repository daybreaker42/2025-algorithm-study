#include <iostream> // 입출력 스트림 사용을 위한 헤더 파일
#include <vector>   // 벡터 컨테이너 사용을 위한 헤더 파일
#include <set>      // set 컨테이너 사용을 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int main() {
    int u, v, caseNum = 1; // u, v는 노드, caseNum은 테스트 케이스 번호
    while (cin >> u >> v && (u >= 0 || v >= 0)) { // u, v를 입력받고 둘 다 0 이상일 때 반복
        if (u == 0 && v == 0) { // u와 v가 모두 0이면 트리를 판별하고 다음 케이스로 넘어감
            cout << "Case " << caseNum++ << " is a tree." << endl; // 트리를 판별하는 메시지 출력
            continue;                                                 // 다음 케이스로 진행
        }

        set<int> nodes;          // 노드 집합
        vector<int> inDegree(100001, 0); // 각 노드의 진입 차수 저장
        bool isTree = true;      // 트리 여부를 나타내는 변수
        int edges = 0;           // 간선 수

        while (u != 0 || v != 0) { // u나 v 중 하나라도 0이 아니면 계속 입력 받음
            if (u == v) isTree = false; // u와 v가 같으면 트리가 아님 (자기 루프)
            nodes.insert(u);        // 노드 집합에 u 추가
            nodes.insert(v);        // 노드 집합에 v 추가
            inDegree[v]++;          // v의 진입 차수 증가
            edges++;                // 간선 수 증가
            cin >> u >> v;          // 다음 간선 정보 입력
        }

        int rootCount = 0; // 루트 노드 수
        for (int node : nodes) { // 모든 노드에 대해
            if (inDegree[node] == 0) { // 진입 차수가 0이면 루트 노드
                rootCount++;            // 루트 노드 수 증가
            } else if (inDegree[node] > 1) { // 진입 차수가 1보다 크면 트리가 아님
                isTree = false;             // 트리 아님
            }
        }

        if (rootCount == 0 && !nodes.empty()) isTree = false; // 루트 노드가 없고 노드가 존재하면 트리가 아님
        if (rootCount > 1) isTree = false;                      // 루트 노드가 1개보다 많으면 트리가 아님
        if (edges != nodes.size() - 1 && !nodes.empty()) isTree = false; // 간선 수가 노드 수 - 1이 아니면 트리가 아님

        cout << "Case " << caseNum++ << " is "; // 케이스 번호 출력
        if (!isTree) cout << "not ";            // 트리가 아니면 "not " 출력
        cout << "a tree." << endl;             // "a tree." 출력
    }
    return 0; // 프로그램 종료
}
