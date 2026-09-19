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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)     return ans;
        queue <TreeNode *> q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            vector <int> lvl(sz);
            for(int i=0; i<sz; i++){
                TreeNode * temp = q.front();
                int idx = (cnt%2==1) ? i : sz - i - 1; lvl[idx] = temp->val;
                if(temp->left)      q.push(temp->left);
                if(temp->right)      q.push(temp->right);
                q.pop();
            }
            ans.push_back(lvl);
            cnt++;
        }
        return ans;
    }
};