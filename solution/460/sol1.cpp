struct Node{
    int cnt,time,key;
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time:cnt < rhs.cnt;
    }
};
class LFUCache {
    int _capacity,time;
    unordered_map<int,pair<int,pair<int,int> > >mp;
    set<Node>S;
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        time = 0;
    }
    
    int get(int key) {
        if (_capacity == 0) return -1;
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        auto its = S.find((Node){(it->second).second.second, (it->second).second.first, key});
        Node tmp = *its;
        S.erase(its);
        tmp.cnt += 1;
        tmp.time = ++time;
        S.insert(tmp);
        (it->second).second.first = time;
        (it->second).second.second = tmp.cnt;
        return (it->second).first;
    }
    
    void put(int key, int value) {
        if (_capacity == 0) return;
        auto it = mp.find(key);
        if (it == mp.end()){
            if (mp.size() == _capacity){
                auto it = S.begin();
                mp.erase(mp.find(it->key));
                S.erase(it);
            }
            mp[key] = make_pair(value, make_pair(++time, 1));
            S.insert((Node){1, time, key});
        }
        else{
            auto its = S.find((Node){(it->second).second.second, (it->second).second.first, key});
            Node tmp = *its;
            S.erase(its);
            tmp.cnt += 1;
            tmp.time = ++time;
            S.insert(tmp);
            (it->second).first = value;
            (it->second).second.first = time;
            (it->second).second.second = tmp.cnt;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]*/

