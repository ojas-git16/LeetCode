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
    vector<vector<int>> func(TreeNode * ptr, int lvl, int axis){
        vector<vector<int>> ans;
        if(ptr){
            ans.push_back({axis, lvl, ptr->val});
            if(ptr->left){
                vector<vector<int>> temp = func(ptr->left, lvl+1, axis-1);
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            if(ptr->right){
                vector<vector<int>> temp = func(ptr->right, lvl+1, axis+1);
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
        }
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v = func(root, 0, 0);
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i = 0; i < v.size();) {
            vector<int> temp;
            int axis = v[i][0];
            while(i < v.size() && v[i][0] == axis) {
                temp.push_back(v[i][2]);
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};