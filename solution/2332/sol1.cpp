class Solution {
public:
    struct Node {
        int L, R;
    };
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        vector<Node> seg;
        int P = 0;
        for (int i = 0; i < passengers.size(); ++i) {
            if (passengers[i] > buses.back()) {
                break;
            }
            if (P + 1 < passengers[i]) {
                seg.push_back((Node){P + 1, passengers[i] - 1});
            }
            P = passengers[i];
        }
        if (P + 1 <= buses.back()) {
            seg.push_back((Node){P + 1, buses.back()});
        }

        int L = 0, R = seg.size() - 1, res = -1;
        function<bool(int)> check = [&](int x) -> bool {
            // cout << x << endl;
            for (int i = 0, j = 0; i < buses.size(); ++i) {
                int c = 0;
                while (c < capacity && j < passengers.size()) {
                    if (x < passengers[j]) {
                        if (j > 0) {
                            if (x > passengers[j - 1]) {
                                if (x <= buses[i]) {
                                    return true;
                                }
                            }
                        } else {
                            if (x <= buses[i]) {
                                return true;
                            }
                        }
                    }
                    if (passengers[j] <= buses[i]) {
                        c++;
                        j++;
                    } else {
                        break;
                    }
                }
                if (c < capacity && x <= buses[i]) {
                    return true;
                }
            }
            return false;
        };
        while (L <= R) {
            int mid = L + ((R - L) >> 1);
            if (check(seg[mid].R)) {
                res = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return seg[res].R;
    }
};
