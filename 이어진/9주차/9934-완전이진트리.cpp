#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
* 백준 9934 - 완전 이진 트리
* 
* 문제 발상:
* 1. 중위 순회 결과가 주어졌을 때 완전 이진 트리를 레벨별로 출력하는 문제
* 2. 완전 이진 트리의 중위 순회 특성:
*    - 중위 순회: 왼쪽 서브트리 → 루트 → 오른쪽 서브트리
*    - 완전 이진 트리에서 중간 인덱스가 항상 루트가 됨
* 3. 분할 정복 방식으로 해결:
*    - 전체 배열의 중간값이 현재 레벨의 루트
*    - 왼쪽 절반을 왼쪽 서브트리로, 오른쪽 절반을 오른쪽 서브트리로 재귀 처리
* 4. 각 레벨별로 노드들을 저장하여 레벨 순서로 출력
*/

vector<int> inorder_result;
vector<vector<int>> levels;

// 중위 순회 결과로부터 트리를 레벨별로 구성
void build_tree(int start, int end, int level) {
    if (start > end) return;
    
    // 중간 인덱스가 현재 서브트리의 루트
    int mid = (start + end) / 2;
    
    // 해당 레벨에 루트 노드 추가
    if (levels.size() <= level) {
        levels.resize(level + 1);
    }
    levels[level].push_back(inorder_result[mid]);
    
    // 왼쪽 서브트리와 오른쪽 서브트리 재귀 처리
    build_tree(start, mid - 1, level + 1);  // 왼쪽 서브트리
    build_tree(mid + 1, end, level + 1);    // 오른쪽 서브트리
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K;
    cin >> K;
    
    int n = pow(2, K) - 1;  // 노드의 총 개수: 2^K - 1
    inorder_result.resize(n);
    
    // 중위 순회 결과 입력
    for (int i = 0; i < n; i++) {
        cin >> inorder_result[i];
    }
    
    // 트리를 레벨별로 구성
    build_tree(0, n - 1, 0);
    
    // 각 레벨별로 노드 출력
    for (int level = 0; level < K; level++) {
        for (int i = 0; i < levels[level].size(); i++) {
            if (i > 0) cout << " ";
            cout << levels[level][i];
        }
        cout << '\n';
    }
    
    return 0;
}
