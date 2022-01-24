/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        vector<TreeNode*> vec;
        queue<TreeNode*> Q;
        Q.push(root);
        for (;;){
            bool flag=0;
            while (!Q.empty()){
                TreeNode* cur=Q.front();Q.pop();
                if (cur->left) vec.push_back(cur->left),flag=1;
                else vec.push_back(NULL);

                if (cur->right) vec.push_back(cur->right),flag=1;
                else vec.push_back(NULL);
            }
            if (!flag) break;
            vector<TreeNode*> t;
            for (int i=0;i<(int)vec.size();++i) t.push_back(vec[i]);
            reverse(t.begin(),t.end());
            for (int i=0;i<(int)vec.size();++i){
                //cout<<(vec[i]->val)<<" "<<(t[i]->val)<<endl;
                if ((vec[i]==NULL && t[i]==NULL) || (vec[i]!=NULL && t[i]!=NULL && vec[i]->val==t[i]->val));
                else return false;
                if (vec[i]!=NULL) Q.push(vec[i]);
            }
            vec.clear();
        }
        return true;
    }
};

