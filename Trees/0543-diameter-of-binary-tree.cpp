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
    int ans = 0;
    int func(TreeNode * ptr){
        if(ptr == nullptr) return 0;
        int lh = 0, rh = 0;
        lh = func(ptr->left);
        rh = func(ptr->right);
        ans = max(ans, lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)     return 0;
        int a = func(root);
        return ans;
    }
};