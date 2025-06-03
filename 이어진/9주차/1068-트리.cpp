#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 1068 - 트리
* 
* 문제 발상:
* 1. 트리에서 특정 노드를 삭제했을 때 리프 노드의 개수를 구하는 문제
* 2. 삭제된 노드와 그 서브트리에 속한 모든 노드들이 제거됨
* 3. 삭제 후 리프 노드 = 자식이 없는 노드 (단, 삭제된 노드는 제외)
* 4. 접근 방법:
*    - 각 노드의 자식 정보를 저장
*    - 삭제할 노드를 제거 (부모-자식 관계에서)
*    - DFS/BFS로 삭제된 노드의 서브트리 전체를 삭제 표시
*    - 남은 노드 중에서 자식이 없는 노드의 개수를 세기
* 5. 루트 노드가 삭제되는 경우 모든 노드가 삭제되므로 리프 노드는 0개
*/

vector<vector<int>> children;
vector<bool> deleted;
int root;

// DFS로 삭제된 노드의 서브트리 전체를 삭제 표시
void delete_subtree(int node) {
    deleted[node] = true;
    
    for (int child : children[node]) {
        if (!deleted[child]) {
            delete_subtree(child);
        }
    }
}

// 리프 노드의 개수를 세는 함수
int count_leaves() {
    int leaf_count = 0;
    
    for (int i = 0; i < children.size(); i++) {
        if (!deleted[i]) {
            // 자식이 없거나, 모든 자식이 삭제된 경우 리프 노드
            bool has_alive_child = false;
            for (int child : children[i]) {
                if (!deleted[child]) {
                    has_alive_child = true;
                    break;
                }
            }
            
            if (!has_alive_child) {
                leaf_count++;
            }
        }
    }
    
    return leaf_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    children.resize(N);
    deleted.resize(N, false);
    
    // 부모 정보 입력 및 자식 관계 설정
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        
        if (parent == -1) {
            root = i;  // 루트 노드
        } else {
            children[parent].push_back(i);  // parent의 자식에 i 추가
        }
    }
    
    int delete_node;
    cin >> delete_node;
    
    // 삭제할 노드와 그 서브트리 삭제
    delete_subtree(delete_node);
    
    // 루트가 삭제된 경우
    if (deleted[root]) {
        cout << 0 << '\n';
    } else {
        // 리프 노드 개수 세기
        cout << count_leaves() << '\n';
    }
    
    return 0;
}
