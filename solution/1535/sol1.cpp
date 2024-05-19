class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cnt = 0;
        int win = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < win) {
                cnt++;
            } else {
                win = arr[i];
                cnt = 1;
            }
            if (cnt == k) {
                return win;
            }
        }
        return win;
    }
};
