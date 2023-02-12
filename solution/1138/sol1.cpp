class Solution {
public:
    string alphabetBoardPath(string target) {
        int px = 0, py = 0;
        vector<pair<int, int>> po(26, {0, 0});
        for (int i = 0; i < 26; ++i) {
            po[i] = { px, py };
            py++;
            if (py == 5) {
                py = 0;
                px += 1;
            }
        }
        string ans = "";
        char prev = 'a';
        for (int i = 0; i < target.size(); ++i) {
            char c = target[i];
            int tx = po[prev - 'a'].first, ty = po[prev - 'a'].second;
            int cx = po[c - 'a'].first, cy = po[c - 'a'].second;
            int dx = cx - tx, dy = cy - ty;

            if (c == 'z') {
                if (dy > 0) {
                    for (int j = 0; j < dy; ++j) {
                        ans += 'R';
                    }
                } else if (dy < 0) {
                    for (int j = 0; j < -dy; ++j) {
                        ans += 'L';
                    }
                }  

                if (dx > 0) {
                    for (int j = 0; j < dx; ++j) {
                        ans += 'D';
                    }
                } else if (dx < 0) {
                    for (int j = 0; j < -dx; ++j) {
                        ans += 'U';
                    }
                }
            } else {
                if (dx > 0) {
                    for (int j = 0; j < dx; ++j) {
                        ans += 'D';
                    }
                } else if (dx < 0) {
                    for (int j = 0; j < -dx; ++j) {
                        ans += 'U';
                    }
                }

                if (dy > 0) {
                    for (int j = 0; j < dy; ++j) {
                        ans += 'R';
                    }
                } else if (dy < 0) {
                    for (int j = 0; j < -dy; ++j) {
                        ans += 'L';
                    }
                }  
            }
            
            ans += '!';
            prev = c;
        }
        return ans;
    }
};
