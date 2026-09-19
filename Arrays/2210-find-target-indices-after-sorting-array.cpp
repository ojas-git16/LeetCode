class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int freq=0, x=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target)
                freq++;
            else if(nums[i]<target)
                x++;
        }
        vector<int> ans;
        for(int i=x; i<x+freq; i++)
            ans.push_back(i);
        return ans;
    }
};