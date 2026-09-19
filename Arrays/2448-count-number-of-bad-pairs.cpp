// Bad pairs = Total pairs - Good pairs
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long ans = n;
        ans = ans*(n-1)/2;
        unordered_map <int,int> mpp;
        long long goodpairs = 0;
        for(int i=0; i<nums.size(); i++){
            goodpairs += mpp[nums[i]-i];
            mpp[nums[i]-i]++;
        }
        ans = ans - goodpairs;
        return ans;
    }
};