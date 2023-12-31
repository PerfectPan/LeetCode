constexpr int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
public:
    int dayOfYear(string date) {
        auto isLeapYear = [](int year) -> bool {
            return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        };

        int year, month, day;
        sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day);
        int res = day;
        for (int i = 0; i < month - 1; ++i) {
            res += days[i] + (i == 1 && isLeapYear(year));
        }
        return res;
    }
};
