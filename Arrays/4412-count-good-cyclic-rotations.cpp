class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int rot = nums.size();
        int ans = 0;
        long long ls=0, rs=0;
        for(int i=0; i<rot; i++){
            if(i<rot/2)
                ls+=nums[i];
            else
                rs+=nums[i];
        }
            if(ls>rs)      ans++;
        for(int i=0; i<rot-1; i++){
            ls-=nums[i%rot];
            rs+=nums[i%rot];
            ls+=nums[(rot/2 + i)%rot];
            rs-=nums[(rot/2 + i)%rot];
            if(ls>rs)      ans++;
        }
        
        return ans;
    }
};