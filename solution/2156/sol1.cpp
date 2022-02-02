class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        vector<int> pow(n + 10), f(n + 10);
        using ll = long long;
        reverse(s.begin(), s.end());
        function<int(int, int)> hash = [&](int l, int r) -> int {
            return (ll)(f[r] - (ll)f[l - 1] * pow[r - l + 1] % modulo + modulo) % modulo;
        };
        
        pow[0] = 1;
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            pow[i] = (ll)pow[i - 1] * power % modulo;
        }
        
        for (int i = 1; i <= n; ++i) {
            f[i] = (ll)((ll)f[i - 1] * power + (s[i - 1] - 'a' + 1)) % modulo;
        }
        
        string ans = "";
        
        for (int i = 1; i + k - 1 <= n; ++i) {
            if (hash(i, i + k - 1) == hashValue) {
                ans = s.substr(i - 1, k);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

