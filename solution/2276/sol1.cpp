// set 维护不相交的线段
class CountIntervals {
private:
    int total = 0;
    set<pair<int, int>> S;
public:
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = S.lower_bound({ left, right });
        if (it == S.end() || it->first > right) {
            if (it != S.begin() && S.size() > 0) {
                it--;
                if (it->second >= left) {
                    left = it->first;
                    right = max(right, it->second);
                    total -= it->second - it->first + 1;
                    S.erase(it);
                    S.insert({ left, right });
                    total += right - left + 1;
                } else {
                    S.insert({ left, right });
                    total += right - left + 1;
                }
            } else {
                S.insert({ left, right });
                total += right - left + 1;
            }
        } else {
            auto begin_it = it;
            if (it != S.begin()) {
                it--;
                if (it->second >= left) {
                    left = it->first;
                    right = max(right, it->second);
                    total -= it->second - it->first + 1;
                    begin_it = it;
                }
                it++;
            }
            while (it != S.end() && it->first <= right) {
                total -= it->second - it->first + 1;
                right = max(right, it->second);
                it++;
            }
            S.erase(begin_it, it);
            S.insert({ left, right });
            total += right - left + 1;
        }
    }
    
    int count() {
        return total;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
