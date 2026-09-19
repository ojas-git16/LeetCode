class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Using Hashset
        // unordered_set <int> st(nums.begin(), nums.end());
        // vector <int> ans(nums.size() - st.size());
        // for(int i=1, j=0; i<=nums.size(); i++)
        //     if(st.count(i)==0)
        //         ans[j++]=i;
        // return ans;

        // Mark as seen by negetion
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int x=abs(nums[i]);
            nums[x-1]=-abs(nums[x-1]);
        }
        vector <int> v;
        for(int i=0; i<n; i++)
            if(nums[i]>0)
                v.push_back(i+1);
        return v;
    }
};