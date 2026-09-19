class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=nums.size(), ptr=0;
        for(int i=0; i<s; i++)
            if(nums[i]!=0)
                swap(nums[ptr++],nums[i]);
    }
};