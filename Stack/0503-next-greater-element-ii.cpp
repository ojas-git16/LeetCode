// Cleaner solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector <int> ans(n,-1);
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();
            if(i<n && !st.empty())
                ans[i]=st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         int u=2;
//         unordered_map <int,int> mpp;
//         stack<int>st;
//         vector <int> ans;
//         vector<int>v;
//         while(u--)
//             for(int i=0; i<n; i++)
//                 v.push_back(nums[i]);
//         for(int i=v.size()-1; i>=0; i--){
//             while(!st.empty() && st.top()<=v[i])
//                 st.pop();
//             if(st.empty())
//                 mpp[i]=-1;
//             else
//                 mpp[i]=st.top();
//             st.push(v[i]);
//         }
//         for(int i=0; i<n; i++)
//             ans.push_back(mpp[i]);
//         return ans;
//     }
// };