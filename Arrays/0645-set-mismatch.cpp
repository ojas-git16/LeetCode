class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int d, m;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int x=abs(nums[i]);
            if(nums[x-1]<0)
                d=x;
            nums[x-1]=-nums[x-1];
        }
        for(int i=0; i<n; i++)
            if(nums[i]>0 && (i+1)!=d)
                m=i+1;
        return {d,m};
    }
};