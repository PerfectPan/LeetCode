class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = accumulate(distance.begin(), distance.end(), 0);
        int t = start, ans = 0;
        if (destination == 0) {
            destination = distance.size();
        }
        while (t != destination) {
            if (t == distance.size()) {
                t = 0;
            }
            ans += distance[t];

            t++;
        }
        return min(ans, sum - ans);
    }
};
