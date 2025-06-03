#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
* 백준 6416 - 트리인가?
* 
* 문제 발상:
* 1. 트리의 조건을 만족하는지 확인하는 문제
* 2. 트리의 조건:
*    - 연결 그래프여야 함 (모든 노드가 연결되어 있어야 함)
*    - 사이클이 없어야 함
*    - n개의 노드가 있다면 n-1개의 간선이 있어야 함
*    - 루트 노드(진입차수가 0인 노드)가 정확히 1개여야 함
*    - 나머지 노드들은 진입차수가 1이어야 함
* 3. 간선 정보를 받아서 각 노드의 진입차수와 전체 노드/간선 개수를 확인
* 4. 빈 그래프(노드가 0개)도 트리로 간주
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int u, v;
    int case_num = 1;
    
    while (true) {
        set<int> nodes;              // 모든 노드를 저장
        map<int, int> indegree;      // 각 노드의 진입차수
        int edge_count = 0;          // 간선의 개수
        
        // 간선 정보 입력
        while (cin >> u >> v) {
            if (u == 0 && v == 0) break;  // 테스트 케이스 종료
            if (u < 0 && v < 0) return 0;  // 전체 입력 종료
            
            nodes.insert(u);
            nodes.insert(v);
            indegree[v]++;  // v로 들어오는 간선 증가
            edge_count++;
        }
        
        // 모든 노드의 진입차수 초기화 (입력에 없던 노드들)
        for (int node : nodes) {
            if (indegree.find(node) == indegree.end()) {
                indegree[node] = 0;
            }
        }
        
        bool is_tree = true;
        int node_count = nodes.size();
        
        // 빈 그래프는 트리
        if (node_count == 0) {
            is_tree = true;
        }
        // 트리 조건 확인
        else {
            // 1. 간선 개수 확인: n개 노드에 n-1개 간선
            if (edge_count != node_count - 1) {
                is_tree = false;
            }
            else {
                // 2. 진입차수 확인: 루트 1개(진입차수 0), 나머지는 진입차수 1
                int root_count = 0;
                for (auto& pair : indegree) {
                    int degree = pair.second;
                    if (degree == 0) {
                        root_count++;
                    } else if (degree != 1) {
                        is_tree = false;
                        break;
                    }
                }
                
                // 루트가 정확히 1개여야 함
                if (root_count != 1) {
                    is_tree = false;
                }
            }
        }
        
        // 결과 출력
        cout << "Case " << case_num << " is ";
        if (is_tree) {
            cout << "a tree." << '\n';
        } else {
            cout << "not a tree." << '\n';
        }
        
        case_num++;
    }
    
    return 0;
}
