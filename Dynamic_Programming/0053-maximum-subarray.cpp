class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int sum=0, i=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            if(maxsum<sum)
                maxsum=sum;
            if(sum<0)
                sum=0;
            i++;
        }
        return maxsum;
    }
};