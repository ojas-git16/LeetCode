class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();

        unordered_set <int> st;
        vector <int> pre(n), post(n);

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            pre[i]=st.size();
        }
        st.clear();
        for(int i=n-1; i>=0; i--){
            st.insert(nums[i]);
            post[i]=st.size();
        }

        vector <int> ans;
        int right;
        for(int i=0; i<n; i++){
            if(i==n-1)
                right=0;
            else
                right=post[i+1];
            ans.push_back(pre[i]-right);
        }
        return ans;
    }
};