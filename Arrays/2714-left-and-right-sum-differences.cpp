class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector <int> ans;
        for(auto num : nums)
            sum+=num;
        int leftsum=0, rightsum=0;
        for(int i=0; i<n; i++){
            rightsum=sum-leftsum-nums[i];
            ans.push_back(abs(leftsum-rightsum));
            leftsum+=nums[i];
        }
        return ans;
    }
};