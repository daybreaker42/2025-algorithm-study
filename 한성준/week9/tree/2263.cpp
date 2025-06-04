#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int n;                       // 트리의 노드 수
vector<int> inorder, postorder, position; // 중위 순회, 후위 순회, 노드의 위치 정보

// 트리를 순회하며 전위 순회 결과를 출력하는 함수
void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return; // 기저 조건: 순회 범위가 유효하지 않으면 종료

    int root = postorder[post_end]; // 후위 순회의 마지막 노드가 루트 노드
    cout << root << " ";           // 루트 노드 출력

    int root_index = position[root]; // 중위 순회에서 루트 노드의 위치
    int left_size = root_index - in_start; // 왼쪽 서브트리의 크기

    // 왼쪽 서브트리 순회
    solve(in_start, root_index - 1, post_start, post_start + left_size - 1);
    // 오른쪽 서브트리 순회
    solve(root_index + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    cin >> n; // 노드 수 입력

    inorder.resize(n + 1);   // 중위 순회 결과 저장 벡터 크기 설정
    postorder.resize(n + 1); // 후위 순회 결과 저장 벡터 크기 설정
    position.resize(n + 1);  // 각 노드의 위치 저장 벡터 크기 설정

    // 중위 순회 결과 입력 및 각 노드의 위치 저장
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }

    // 후위 순회 결과 입력
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    // 트리의 전위 순회 결과 출력
    solve(1, n, 1, n);

    return 0; // 프로그램 종료
}
