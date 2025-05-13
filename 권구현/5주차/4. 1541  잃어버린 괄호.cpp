#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<char> ops;
    string num = "";

    for (char c : s) {
        if (c == '+' || c == '-') {
            nums.push_back(stoi(num));
            ops.push_back(c);
            num = "";
        } else {
            num += c;
        }
    }
    nums.push_back(stoi(num));

    int result = nums[0];
    bool minus = false;

    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '-') minus = true;
        if (minus) result -= nums[i + 1];
        else result += nums[i + 1];
    }

    cout << result << '\n';
}#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<char> ops;
    string num = "";

    for (char c : s) {
        if (c == '+' || c == '-') {
            nums.push_back(stoi(num));
            ops.push_back(c);
            num = "";
        } else {
            num += c;
        }
    }
    nums.push_back(stoi(num));

    int result = nums[0];
    bool minus = false;

    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '-') minus = true;
        if (minus) result -= nums[i + 1];
        else result += nums[i + 1];
    }

    cout << result << '\n';
}
