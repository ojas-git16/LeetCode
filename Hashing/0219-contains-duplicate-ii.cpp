class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(i > k)
                st.erase(nums[i - k - 1]);
            int sz = st.size();
            st.insert(nums[i]);
            if(sz == st.size())
                return true;
        }
        return false;
    }
};