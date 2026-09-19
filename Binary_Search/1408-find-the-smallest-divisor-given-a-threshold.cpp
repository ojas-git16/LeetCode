class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int maxm=INT_MIN;
        for(int num : nums)
            maxm=max(num,maxm);
        int low=1, high=maxm;
        if(t==nums.size())
            return maxm;

        while(low<=high){
            int sum=0;
            int mid=low+(high-low)/2;
            for(int i=0; i<nums.size(); i++){
                sum+=(nums[i]+mid-1)/mid;
                if(sum>t){
                    low=mid+1;
                    break;
                }
            }
            if(sum<=t)
                high=mid-1;
        }
        return low;
    }
};