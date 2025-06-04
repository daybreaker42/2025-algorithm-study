#include <iostream>
#include <map>
using namespace std;

/*
* 백준 1991 - 트리 순회
* 
* 문제 발상:
* 1. 이진 트리의 세 가지 순회 방법을 구현하는 문제
* 2. 전위 순회(Preorder): 루트 → 왼쪽 서브트리 → 오른쪽 서브트리
* 3. 중위 순회(Inorder): 왼쪽 서브트리 → 루트 → 오른쪽 서브트리
* 4. 후위 순회(Postorder): 왼쪽 서브트리 → 오른쪽 서브트리 → 루트
* 5. 재귀적으로 구현하며, '.'은 자식이 없음을 의미
* 6. 각 노드를 문자로 표현하므로 map을 사용하여 노드 정보 저장
*/

struct Node {
    char left;
    char right;
};

map<char, Node> tree;

// 전위 순회: 루트 → 왼쪽 → 오른쪽
void preorder(char node) {
    if (node == '.') return;
    
    cout << node;                    // 루트 방문
    preorder(tree[node].left);       // 왼쪽 서브트리
    preorder(tree[node].right);      // 오른쪽 서브트리
}

// 중위 순회: 왼쪽 → 루트 → 오른쪽
void inorder(char node) {
    if (node == '.') return;
    
    inorder(tree[node].left);        // 왼쪽 서브트리
    cout << node;                    // 루트 방문
    inorder(tree[node].right);       // 오른쪽 서브트리
}

// 후위 순회: 왼쪽 → 오른쪽 → 루트
void postorder(char node) {
    if (node == '.') return;
    
    postorder(tree[node].left);      // 왼쪽 서브트리
    postorder(tree[node].right);     // 오른쪽 서브트리
    cout << node;                    // 루트 방문
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // 트리 정보 입력
    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent] = {left, right};
    }
    
    // 세 가지 순회 결과 출력
    preorder('A');   // 전위 순회 (루트는 항상 A)
    cout << '\n';
    
    inorder('A');    // 중위 순회
    cout << '\n';
    
    postorder('A');  // 후위 순회
    cout << '\n';
    
    return 0;
}
