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
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans;
        if(root==NULL)      return ans;
        stack <TreeNode *> st;
        TreeNode * ptr = root;
        while(ptr || !st.empty()){
            if(ptr){
                st.push(ptr);
                ptr = ptr->left;
            }
            else{
                TreeNode * temp = st.top()->right;
                if(temp==NULL){
                    while(!st.empty() && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    ptr = temp;
            }
        }
        return ans;
    }
};