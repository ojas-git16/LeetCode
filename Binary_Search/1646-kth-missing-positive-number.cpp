class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high=arr.size()-1;
        if(arr[low]-1>=k)
            return k;
        if(arr[high]-high-1 < k)
            return arr[high] + (k - (arr[high]-high-1));
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]-mid-1 >= k)
                high=mid-1;
            else
                low=mid+1;
        }
        return arr[high]+k-(arr[high]-high-1);
    }
};

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int curr = 1;
//         int i = 0;
//         while(k > 0) {
//             if(i < arr.size() && arr[i] == curr)
//                 i++;
//             else {
//                 k--;
//                 if(k == 0)
//                     return curr;
//             }
//             curr++;
//         }
//         return curr;
//     }
// };