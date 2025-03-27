#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// 각 달의 일 수 (비윤년 가정)
int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 달 => 일 변환
int monthToDays(int month) {
    int days = 0;
    for (int i = 0; i < month - 1; ++i) {
        days += monthDays[i];
    }
    return days;
}

// "YYYY-MM-DD HH:MM" 형식의 문자열에서 분 단위 시간 계산 (연도 무시)
int timeToMinutes(const string& ymd, const string& time) {
    int month = stoi(ymd.substr(5, 2));
    int day = stoi(ymd.substr(8, 2));
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return monthToDays(month) * 1440 + (day - 1) * 1440 + hour * 60 + minute;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int len;
    string sDuration;
    int finePerMinute;
    cin >> len >> sDuration >> finePerMinute;

    int allowedDurationMinutes = 0;
    allowedDurationMinutes += stoi(sDuration.substr(0, 3)) * 1440; // Day
    allowedDurationMinutes += stoi(sDuration.substr(4, 2)) * 60;    // Hour
    allowedDurationMinutes += stoi(sDuration.substr(7, 2));        // Minute

    map<string, map<string, int>> rentals; // {part: {name: rentalStartTime}}
    map<string, long long> fineReports;

    for (int i = 0; i < len; ++i) {
        string ymd, time, part, name;
        cin >> ymd >> time >> part >> name;

        int currentTime = timeToMinutes(ymd, time);

        if (rentals.count(part) && rentals[part].count(name)) {
            int rentalStartTime = rentals[part][name];
            int rentalDurationMinutes = currentTime - rentalStartTime;

            if (rentalDurationMinutes > allowedDurationMinutes) {
                fineReports[name] += (long long)(rentalDurationMinutes - allowedDurationMinutes) * finePerMinute;
            }
            rentals[part].erase(name);
            if (rentals[part].empty()) {
                rentals.erase(part);
            }
        } else {
            rentals[part][name] = currentTime;
        }
    }

    if (fineReports.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& user : fineReports) {
            cout << user.first << " " << user.second << '\n';
        }
    }

    return 0;
}