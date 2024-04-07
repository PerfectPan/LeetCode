// 答案等价于维护的继承树的前序遍历
class ThroneInheritance {
private:
    string rt = "";
    map<string, vector<string>> t;
    unordered_set<string> s;
public:
    ThroneInheritance(string kingName) {
        rt = kingName;
        t[kingName] = {};
    }
    
    void birth(string parentName, string childName) {
        t[parentName].push_back(childName);
    }
    
    void death(string name) {
        s.insert(name);
    }

    void dfs(string u, vector<string>& ans) {
        if (!s.count(u)) {
            ans.push_back(u);
        }
        for (auto& v: t[u]) {
            dfs(v, ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(rt, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
