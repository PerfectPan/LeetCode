class LockingTree {
public:
    vector<vector<int>> G;
    vector<int> lk;
    vector<int> pa;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        G.resize(n);
        lk.resize(n, -1);
        pa = parent;
        for (int i = 0; i < pa.size(); ++i) {
            if (pa[i] != -1) {
                G[pa[i]].push_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if (lk[num] == -1) {
            lk[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (lk[num] == user) {
            lk[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (lk[num] == -1) {
            int p = num;
            while (p != -1) {
                if (lk[p] != -1) {
                    return false;
                }
                p = pa[p];
            }
            if (dfs(num)) {
                lk[num] = user;
                return true;
            }
        }   
        return false;
    }

    bool dfs(int u) {
        bool flag = lk[u] != -1;
        lk[u] = -1;
        for (int v: G[u]) {
            flag |= dfs(v);
        }
        return flag;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
