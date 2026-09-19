class Solution {
public:
    int splitArray(vector<int>& arr, int m) {
        if(m>arr.size())
        return -1;

    int arrsum=0, maxm=-1;
    for(int num : arr){
        arrsum+=num;
        maxm=max(num,maxm);
    }

    int low=maxm, high=arrsum;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int sum=0, cnt=1, maxsum=0;
        for(int i=0; i<arr.size(); i++){
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else sum+=arr[i];
        }
        
        if(cnt<=m){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;

    }
    return ans;
    }
};