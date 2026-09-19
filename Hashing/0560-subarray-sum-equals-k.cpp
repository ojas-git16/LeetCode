class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0, sum=0;
        unordered_map <long long, int> mpp;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(mpp.find(sum-k) != mpp.end())
                count+=mpp[sum-k];
            mpp[sum]++;
        }
        return count;
    }
};