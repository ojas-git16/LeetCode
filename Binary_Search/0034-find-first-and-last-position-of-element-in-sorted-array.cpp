class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int mid;
        int a=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target)
                    a=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        int z=a;
        low=0, high=nums.size()-1;
        while(low <= high){
            mid=(low+high)/2;
            if(target>=nums[mid]){
                if(nums[mid]==target)
                    z=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return {a,z};
    }
};