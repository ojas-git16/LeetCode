class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(nums.size()==0)
            return 0;
        unordered_set <int> st;
        for(int i=0; i<n; i++)
            st.insert(nums[i]);
        
        for(int num : st){
            if(st.find(num-1)==st.end()){
                int cnt=1;
                int x=num;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(nums.size()==0)
//             return 0;
//         int ans=1, count=1;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n-1; i++){
//             if(nums[i]+1==nums[i+1]){
//                 count++;
//                 ans=max(count,ans);
//             }
//             else if(nums[i]==nums[i+1])
//                 continue;
//             else
//                 count=1;
//         }
//         return ans;
//     }
// };