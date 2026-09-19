class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int ans=INT_MAX, maxm=0;
        if ((long long)m * k > arr.size())
            return -1;
        for (int day : arr)
            maxm = max(day, maxm);
        int low=1, high=maxm;
        while(low<=high){
            int day=low+(high-low)/2;
            int flower=0, bouque=0;
            for(int i=0; i<arr.size(); i++){
                if(arr[i]<=day)  flower++;
                else    flower=0;

                if(flower==k){
                    bouque++;
                    flower=0;
                }
                
                if(bouque>=m){
                    ans=min(ans,day);
                    high=day-1;
                    break;
                }
            }
            if(bouque<m)
                low=day+1;
            
        }
        return ans;
    }
};