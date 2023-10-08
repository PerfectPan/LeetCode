class StockPrice {
public:
    unordered_map<int, int> mp;
    set<pair<int, int>> st;
    int current_time = 0;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            auto it = st.find({mp[timestamp], timestamp});
            st.erase(it);
        }
        mp[timestamp] = price;
        st.insert({price, timestamp});
        if (current_time <= timestamp) {
            current_time = timestamp;
        }
    }
    
    int current() {
        return mp[current_time];
    }
    
    int maximum() {
        return st.rbegin()->first;
    }
    
    int minimum() {
        return st.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
