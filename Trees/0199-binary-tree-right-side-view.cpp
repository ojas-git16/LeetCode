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
    map <int, TreeNode*> mpp;
    void func(TreeNode * ptr, int lvl){
        if(ptr){
            mpp[lvl]=ptr;
            func(ptr->left, lvl+1);
            func(ptr->right, lvl+1);
        }        
    }
    vector<int> rightSideView(TreeNode* root) {
        func(root, 0);
        vector <int> ans;
        for(auto [key,ptr] : mpp)
            ans.push_back(ptr->val);
        return ans;
    }
};