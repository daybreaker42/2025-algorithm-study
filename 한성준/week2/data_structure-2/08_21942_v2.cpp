#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct DateTime {
    int month, day, hour, minute;

    DateTime(string date, string time) {
        month = stoi(date.substr(0, 2));
        day = stoi(date.substr(3, 2));
        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
    }

    int toMinutes() const {
        return ((month - 1) * 30 + day - 1) * 24 * 60 + hour * 60 + minute;
    }
};

int calculateOverdueFee(DateTime borrowTime, DateTime returnTime, int limitMinutes, int feePerMinute) {
    int borrowMinutes = borrowTime.toMinutes();
    int returnMinutes = returnTime.toMinutes();
    int overdueMinutes = returnMinutes - borrowMinutes - limitMinutes;
    return overdueMinutes > 0 ? overdueMinutes * feePerMinute : 0;
}

int main() {
    fastio;
    int n, feePerMinute;
    string borrowLimit;
    cin >> n >> borrowLimit >> feePerMinute;
    
    int limitDays = stoi(borrowLimit.substr(0, borrowLimit.find('/')));
    int limitHours = stoi(borrowLimit.substr(borrowLimit.find('/') + 1, 2));
    int limitMinutes = stoi(borrowLimit.substr(borrowLimit.find('/') + 4, 2));
    int totalLimitMinutes = (limitDays * 24 + limitHours) * 60 + limitMinutes;

    map<string, pair<DateTime, string>> borrowMap;
    map<string, long long> fineMap;

    for (int i = 0; i < n; i++) {
        string date, time, part, user;
        cin >> date >> time >> part >> user;
        DateTime currTime(date, time);

        string key = part + "#" + user;
        if (borrowMap.count(key)) {
            auto [borrowTime, storedUser] = borrowMap[key];
            fineMap[storedUser] += calculateOverdueFee(borrowTime, currTime, totalLimitMinutes, feePerMinute);
            borrowMap.erase(key);
        } else {
            borrowMap[key] = {currTime, user};
        }
    }

    if (fineMap.empty()) {
        cout << -1 << '\n';
    } else {
        for (const auto& [user, fine] : fineMap) {
            if (fine > 0) {
                cout << user << ' ' << fine << '\n';
            }
        }
    }
    return 0;
}
