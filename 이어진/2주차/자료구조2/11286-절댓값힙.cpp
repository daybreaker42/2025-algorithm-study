#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> abs_heap;
    for (int i = 0; i < n; ++i) {
        int command;
        std::cin >> command;
        if (command != 0) {
            abs_heap.push({std::abs(command), command});
        } else {
            if (abs_heap.empty()) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << abs_heap.top().second << std::endl;
                abs_heap.pop();
            }
        }
    }
    return 0;
}