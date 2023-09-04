/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ans = "";
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            ans += ",";
            return;
        } else {
            ans += "," + to_string(root->val);
        }

        dfs(root->left);
        dfs(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans = "";
        dfs(root);
        return ans.substr(1);
    }

    TreeNode* rebuild(vector<int>& res, int& idx) {
        if (res.size() == idx) {
            return nullptr;
        }

        if (res[idx] == -1) {
            return nullptr;
        }

        TreeNode* rt = new TreeNode(res[idx]);
        idx++;
        rt->left = rebuild(res, idx);
        idx++;
        rt->right = rebuild(res, idx);

        return rt;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> res;
        for (int i = 0; i < data.size(); ++i) {
            int l = i;
            string str = "";
            while (l < data.size() && data[l] != ',') {
                str += data[l];
                l++;
            }
            if (str == "") {
                res.push_back(-1);
            } else {
                res.push_back(stoi(str));
            }
            i = l;
        }
        int idx = 0;
        return rebuild(res, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
