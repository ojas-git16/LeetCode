class Solution {
public:
    bool check(vector<int>& nums) {
        int x=0, s=nums.size();
        for(int i=0; i<s-1; i++)
            if(nums[i+1]<nums[i])
                x++;
        if(x==0)
            return true;
        if(x==1 && nums[0]>=nums[s-1] )
            return true;
        return false;
    }
};