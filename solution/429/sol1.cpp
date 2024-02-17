/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> Q;
        if (root != nullptr) {
            Q.push(root);
        }
        while (!Q.empty()) {
            int sz = Q.size();
            res.push_back(vector<int>());
            for (int i = 1; i <= sz; ++i) {
                auto node = Q.front(); Q.pop();
                res.back().push_back(node->val);
                for (auto& v: node->children) {
                    Q.push(v);
                }
            }
        }
        return res;
    }
};
