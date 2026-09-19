class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0, maxm=0;
        for(int num : arr){
            sum+=num;
            maxm=max(maxm,num);
        }
        int low=maxm, high=sum, ans=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int wgt=0, d=1;
            for(int num : arr){
                if(wgt+num>mid){
                    d++;
                    wgt=0;
                }
                wgt+=num;

                if(d>days){
                    low=mid+1;
                    break;
                }
            }
            if (d > days) {
                low = mid + 1;
            } else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};