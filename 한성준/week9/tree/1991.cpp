#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

// 이진 트리를 표현하는 구조체
struct Node {
    char data; // 노드의 데이터
    Node* left;  // 왼쪽 자식 노드 포인터
    Node* right; // 오른쪽 자식 노드 포인터
};

// 새로운 노드를 생성하는 함수
Node* createNode(char data) {
    Node* newNode = new Node(); // 새로운 노드 생성
    newNode->data = data;        // 데이터 설정
    newNode->left = newNode->right = nullptr; // 자식 노드 포인터 초기화
    return newNode; // 새로운 노드 반환
}

// 전위 순회 (Preorder Traversal): Root -> Left -> Right
void preorder(Node* root) {
    if (root) { // 노드가 존재하면
        cout << root->data;   // 현재 노드 데이터 출력
        preorder(root->left);  // 왼쪽 서브트리 순회
        preorder(root->right); // 오른쪽 서브트리 순회
    }
}

// 중위 순회 (Inorder Traversal): Left -> Root -> Right
void inorder(Node* root) {
    if (root) { // 노드가 존재하면
        inorder(root->left);   // 왼쪽 서브트리 순회
        cout << root->data;    // 현재 노드 데이터 출력
        inorder(root->right);  // 오른쪽 서브트리 순회
    }
}

// 후위 순회 (Postorder Traversal): Left -> Right -> Root
void postorder(Node* root) {
    if (root) { // 노드가 존재하면
        postorder(root->left);  // 왼쪽 서브트리 순회
        postorder(root->right); // 오른쪽 서브트리 순회
        cout << root->data;    // 현재 노드 데이터 출력
    }
}

int main() {
    int n;       // 노드의 개수
    cin >> n;    // 노드의 개수 입력

    vector<Node*> nodes(n); // 노드 포인터 벡터 생성
    // 각 노드 초기화
    for (int i = 0; i < n; ++i) {
        nodes[i] = createNode('A' + i); // 'A'부터 시작하는 알파벳으로 노드 데이터 설정
    }

    // 트리 구성
    for (int i = 0; i < n; ++i) {
        char node, left, right; // 노드, 왼쪽 자식, 오른쪽 자식
        cin >> node >> left >> right; // 노드 정보 입력
        int index = node - 'A';       // 노드의 인덱스 계산

        // 왼쪽 자식 설정
        if (left != '.') {
            nodes[index]->left = nodes[left - 'A']; // '.'이 아니면 왼쪽 자식 설정
        }
        // 오른쪽 자식 설정
        if (right != '.') {
            nodes[index]->right = nodes[right - 'A']; // '.'이 아니면 오른쪽 자식 설정
        }
    }

    // 루트 노드는 'A'
    Node* root = nodes[0];

    // 순회 결과 출력
    preorder(root); // 전위 순회
    cout << endl;
    inorder(root);  // 중위 순회
    cout << endl;
    postorder(root); // 후위 순회
    cout << endl;

    return 0; // 프로그램 종료
}
