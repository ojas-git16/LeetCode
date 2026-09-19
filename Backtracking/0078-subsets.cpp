class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> temp, vector<int> &nums, int i){     
        if(i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        func(ans, temp, nums, i+1);
        temp.push_back(nums[i]);
        func(ans, temp, nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, temp, nums, 0);
        return ans;
    }
};