#include <iostream>
#include <string>
#include <map>
#include <iomanip>

int main() {
    std::map<std::string, int> tree_counts;
    int total_trees = 0;
    std::string tree_name;
    while (std::getline(std::cin, tree_name)) {
        tree_counts[tree_name]++;
        total_trees++;
    }
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& pair : tree_counts) {
        double percentage = (static_cast<double>(pair.second) / total_trees) * 100.0;
        std::cout << pair.first << " " << percentage << std::endl;
    }
    return 0;
}   