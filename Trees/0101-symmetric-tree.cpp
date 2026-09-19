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
    bool issym(TreeNode * l, TreeNode * r){
        if(l==nullptr && r==nullptr)
            return true;
        else if(l==nullptr || r==nullptr)
            return false;
        bool a = issym(l->left, r->right);
        bool b = issym(l->right, r->left);
        bool c = false;
        if(l->val == r->val)
            c = true;
        if( a && b && c )       return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if(root->left == nullptr || root->right == nullptr)
            return false;
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        return issym(left, right);        
    }
};