class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int count=0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])   //To eliminate duplicates
                continue;
            if(nums[i]<=k+count){
                count++;
                sum -= nums[i];
            }
        }
        long long n = k + count;
        sum += n*(n+1)/2;
        return sum;     
    }
};