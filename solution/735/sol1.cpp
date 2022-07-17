class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) {
                stk.push(i);
            } else {
                bool flag = false;
                while (stk.size() > 0) {
                    int item = stk.top();
                    if (asteroids[item] <= -asteroids[i]) {
                        stk.pop();
                    }
                    if (asteroids[item] >= -asteroids[i]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    res.push_back(i);
                }
            }
        }
        while (stk.size() > 0) {
            int item = stk.top();
            res.push_back(item);
            stk.pop();
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            res[i] = asteroids[res[i]];
        }
        return res;
    }
};

