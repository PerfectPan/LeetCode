class ATM {
private:
    vector<int> cnt;
    array<int, 5> a;
public:
    ATM(): cnt(5, 0), a({20, 50, 100, 200, 500}) {
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); ++i) {
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        for (int i = (int)cnt.size() - 1; i >= 0; --i) {
            int take = min(cnt[i], amount / a[i]);
            res[i] += take;
            amount -= take * a[i];
        }
        if (amount > 0) {
            return { -1 };
        }
        for (int i = 0; i < res.size(); ++i) {
            cnt[i] -= res[i];
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
