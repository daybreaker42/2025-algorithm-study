#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <cmath>    // 수학 함수를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int k;                  // 트리의 높이
vector<int> inorder;    // 중위 순회 결과 저장
vector<vector<int>> levels; // 각 레벨별 노드 저장

// 트리를 구성하고 각 레벨에 노드를 저장하는 함수
void solve(int start, int end, int level) {
    if (start > end) return; // 기저 조건: 순회 범위가 유효하지 않으면 종료

    int mid = (start + end) / 2; // 중간 지점 계산
    levels[level].push_back(inorder[mid]); // 해당 레벨에 노드 추가

    // 왼쪽 서브트리 구성
    solve(start, mid - 1, level + 1);
    // 오른쪽 서브트리 구성
    solve(mid + 1, end, level + 1);
}

int main() {
    cin >> k; // 트리의 높이 입력

    int size = pow(2, k) - 1; // 전체 노드 수 계산
    inorder.resize(size);      // 중위 순회 결과 저장 벡터 크기 설정
    levels.resize(k);         // 각 레벨별 노드 저장 벡터 크기 설정

    // 중위 순회 결과 입력
    for (int i = 0; i < size; ++i) {
        cin >> inorder[i];
    }

    // 트리 구성 및 각 레벨별 노드 저장
    solve(0, size - 1, 0);

    // 각 레벨별 노드 출력
    for (int i = 0; i < k; ++i) {
        for (int node : levels[i]) {
            cout << node << " "; // 노드 출력
        }
        cout << endl; // 레벨 변경
    }

    return 0; // 프로그램 종료
}
