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
    int func(TreeNode* ptr, int cnt){
        int ans=0;
        if(ptr->left)           ans = func(ptr->left, cnt+1);
        if(ptr->right)     ans = max(ans, func(ptr->right, cnt+1));

        if(!ptr->left && !ptr->right)           return cnt;
        return ans;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr)        return 0;
        return func(root, 1);
    }
};