class FrequencyTracker {
private:
    map<int, int> mp;
    multiset<int> S;
public:
    FrequencyTracker() {
    }
    
    void add(int number) {
        mp[number] += 1;
        if (mp[number] > 1) {
            auto itr = S.find(mp[number] - 1);
            if (itr != S.end()){
                S.erase(itr);
            }
        }
        S.insert(mp[number]);
    }
    
    void deleteOne(int number) {
        if (mp.count(number) && mp[number] > 0) {
            mp[number] -= 1;
            auto itr = S.find(mp[number] + 1);
            if (itr != S.end()){
                S.erase(itr);
            }
            S.insert(mp[number]);
        }
    }
    
    bool hasFrequency(int frequency) {
        return S.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
