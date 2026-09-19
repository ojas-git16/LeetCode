class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector <int> v;
        int x=nums.size();
        int count=0;
        for(int i=0; i<x-1; i++)
        {
            if(nums[i]!=nums[i+1])
            {
                v.push_back(nums[i]);
                count++;
            }
        }
        if(x!=0)
            count++;
        v.push_back(nums[x-1]);
        for(int i=0; i<v.size(); i++)
            nums[i]=v[i];
        return count;
    }
};