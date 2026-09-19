class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map <int, int> mpp;
        for(int i=0; i<n; i++)
            mpp[nums[i]]++;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]]==3){
                int k, j;
                for(j= i+1; j<n; j++)
                    if(nums[i]==nums[j]){
                        k=j;
                        break;
                    }
                k+=(j-i);
                if(k<n && nums[k]==nums[i])
                    ans++;
            }
        }
        return ans;
        
    }
};