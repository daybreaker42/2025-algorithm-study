#include <iostream>
#include <string>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::set<std::string> s;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        s.insert(str);
    }
    int count = 0;
    for (int i = 0; i < m; ++i) {
        std::string str;
        std::cin >> str;
        if (s.count(str)) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}