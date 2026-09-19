class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), idx=-1, i;
        int minel=INT_MAX, minidx;
        for(i=n-1; i>0; i--)
            if(nums[i-1]<nums[i]){
                idx=i-1;
                break;}
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;}
        for(int j=idx+1; j<n; j++)
            if(nums[j]>nums[idx] && minel>nums[j]){
                minel=nums[j];
                minidx=j;}
        swap(nums[minidx],nums[idx]);
        sort(nums.begin()+idx+1,nums.end());
        return;
    }
};