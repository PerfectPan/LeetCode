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
class FindElements {
private:
    unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        rebuild(root, 0);
    }

    void rebuild(TreeNode* root, int val) {
        if (!root) {
            return;
        }
        root->val = val;
        s.insert(val);
        rebuild(root->left, val * 2 + 1);
        rebuild(root->right, val * 2 + 2);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
