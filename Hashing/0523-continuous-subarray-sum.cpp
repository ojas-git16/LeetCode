class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0;
        unordered_map <int,int> mpp;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum%k;
            // In constraints, nums[i] > 0
            // For negetives, see Q.974
            if(i>0 && rem==0)
                return true;
            if(mpp.find(rem)!=mpp.end()){
                if(i-mpp[rem]>=2)
                    return true;
            }
            else
                mpp[rem]=i;
        }
        return false;
    }
};
// (sum-kn)