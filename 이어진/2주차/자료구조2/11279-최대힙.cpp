#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::priority_queue<int> max_heap;
    for (int i = 0; i < n; ++i) {
        int command;
        std::cin >> command;
        if (command > 0) {
            max_heap.push(command);
        } else {
            if (max_heap.empty()) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << max_heap.top() << std::endl;
                max_heap.pop();
            }
        }
    }
    return 0;
}