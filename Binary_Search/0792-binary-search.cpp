// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low=0, high=nums.size()-1;
//         while(low<=high){
//             int mid = (low + high)/2;
//             if(target>nums[mid])
//                 low=mid+1;
//             else if(target<nums[mid])
//                 high=mid-1;
//             else
//                 return mid;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int bs(vector <int> &arr, int low, int high, int target){
        int mid=(low + high)/2;
        if(low>high)
            return -1;
        if(target>arr[mid])
            return bs(arr,mid+1,high, target);
        else if(target<arr[mid])
            return bs(arr,low,mid-1, target);
        return mid;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1, target);
    }
};