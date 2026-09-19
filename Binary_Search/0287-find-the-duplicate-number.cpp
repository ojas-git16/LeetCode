class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums.size();
        for(int i=0; i<s; i++)
        {
            int idx=abs(nums[i]);
            if(nums[idx]<0)
                return idx;
            nums[idx]=-nums[idx];
        }
        return -1;
    }
};