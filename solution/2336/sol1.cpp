class SmallestInfiniteSet {
public:
    set<int> S;
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        for (int i = 1; ; ++i) {
            if (S.find(i) == S.end()) {
                S.insert(i);
                return i;
            }
        }
    }
    
    void addBack(int num) {
        auto it = S.find(num);
        if (it != S.end()) {
            S.erase(it);
        }
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
