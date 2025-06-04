#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <functional> // 함수 객체를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int main() {
    int n;       // 노드의 개수
    cin >> n;    // 노드의 개수 입력

    vector<int> parent(n); // 부모 노드 정보 저장
    int root;              // 루트 노드
    // 부모 노드 정보 입력 및 루트 노드 찾기
    for (int i = 0; i < n; ++i) {
        cin >> parent[i]; // 부모 노드 정보 입력
        if (parent[i] == -1) { // 부모가 -1이면 루트 노드
            root = i;          // 루트 노드 설정
        }
    }

    int deleteNode; // 삭제할 노드
    cin >> deleteNode; // 삭제할 노드 입력

    vector<bool> isDeleted(n, false); // 삭제 여부 저장
    // 삭제할 노드의 서브트리를 삭제하는 함수
    function<void(int)> deleteSubtree = [&](int node) {
        isDeleted[node] = true; // 현재 노드 삭제 처리
        // 현재 노드의 자식 노드들을 삭제
        for (int i = 0; i < n; ++i) {
            if (parent[i] == node) { // 현재 노드가 부모인 경우
                deleteSubtree(i);    // 자식 노드 삭제
            }
        }
    };

    // 삭제할 노드의 서브트리 삭제
    deleteSubtree(deleteNode);

    // 루트 노드를 삭제하는 경우
    if (deleteNode == root) {
        cout << 0 << endl; // 리프 노드 개수는 0
        return 0;          // 프로그램 종료
    }

    int leafCount = 0; // 리프 노드 개수
    // 리프 노드 개수 계산
    for (int i = 0; i < n; ++i) {
        if (!isDeleted[i]) { // 삭제되지 않은 노드인 경우
            bool isLeaf = true; // 리프 노드 여부
            // 현재 노드가 리프 노드인지 확인
            for (int j = 0; j < n; ++j) {
                if (parent[j] == i && !isDeleted[j]) { // 자식 노드가 있고 삭제되지 않은 경우
                    isLeaf = false; // 리프 노드가 아님
                    break;           // 더 이상 확인할 필요 없음
                }
            }
            // 리프 노드인 경우
            if (isLeaf) {
                leafCount++; // 리프 노드 개수 증가
            }
        }
    }

    cout << leafCount << endl; // 리프 노드 개수 출력

    return 0; // 프로그램 종료
}
