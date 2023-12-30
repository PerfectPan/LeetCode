// Zeller's Algorithm
const string ans[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int index = 0, c, y, m, d;
	    if (month <= 2) {
		    c = (year - 1) / 100;
		    y = (year - 1) % 100;
		    m = month + 12;
		    d = day;
	    }
	    else {
		    c = year / 100;
		    y = year % 100;
		    m = month;
		    d = day;
	    }
	    index = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	    index = index >= 0 ? index % 7 : index % 7 + 7;
        return ans[index];
    }
};
