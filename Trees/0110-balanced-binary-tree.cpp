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
    pair<int, bool> func(TreeNode* ptr, int cnt, bool b){
        pair<int, bool> lh={cnt,true}, rh={cnt, true};
        if(ptr->left)           lh = func(ptr->left, cnt+1, true);
        if(ptr->right)          rh = func(ptr->right, cnt+1, true);
        if(!ptr->left && !ptr->right)           return {cnt, true};
        if(abs(lh.first-rh.first)>1 || lh.second == false || rh.second == false)        return {0,false};
        int a=rh.first;
        if(lh.first >= rh.first)    a=lh.first;
        return {a, true};
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)      return true;
        return func(root, 1, true).second;
    }
};