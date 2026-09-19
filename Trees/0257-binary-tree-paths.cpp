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
    vector<string> ans;
    void func(TreeNode* ptr, string s){
        if(ptr)     s+=to_string(ptr->val);

        if(ptr->left==NULL && ptr->right==NULL)
            ans.push_back(s);
        s+="->";
        if(ptr->left)   func(ptr->left, s); 
        if(ptr->right)  func(ptr->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        func(root, "");
        return ans;   
    }
};