/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> Q;
        Q.push({ root, 0 });
        while (!Q.empty()) {
            map<int, vector<int>> mp2;
            queue<pair<TreeNode*, int>> Q2;
            while (!Q.empty()) {
                const auto [node, y] = Q.front(); Q.pop();
                mp2[y].push_back(node->val);
                if (node->left) {
                    Q2.push({node->left, y - 1});
                }
                if (node->right) {
                    Q2.push({node->right, y + 1});
                }
            }
            for (auto& [col, ls]: mp2) {
                sort(ls.begin(), ls.end());
                for (int& num: ls) {
                    mp[col].push_back(num);
                }
            }

            Q.swap(Q2);
        }

        vector<vector<int>> res;
        for (auto& [_, ls]: mp) {
            res.emplace_back(ls);
        }

        return res;
    }
};
