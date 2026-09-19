class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i) {
        ans.push_back(temp);
        for(int j = i; j < nums.size(); j++) {
            // Skip duplicate choices at the same level
            if(j > i && nums[j] == nums[j-1])
                continue;
            temp.push_back(nums[j]);
            func(ans, temp, nums, j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, temp, nums, 0);
        return ans;
    }
};