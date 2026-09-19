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
    int ans = INT_MIN;
    int dia(TreeNode * ptr){
        if(ptr == nullptr)      return 0;
        int ls = max(0, dia(ptr->left));
        int rs = max(0, dia(ptr->right));
        ans = max(ans, ls+rs+ptr->val);
        return max(ls,rs)+ptr->val;
    }
    int maxPathSum(TreeNode* root) {
        int a = dia(root);
        return ans;
    }
};