// Using stack O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map <int,int> mpp;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
            if(st.empty())
                mpp[nums2[i]]=-1;
            else
                mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto num:nums1)
            ans.push_back(mpp[num]);
        return ans;
    }        
};


// O(n^2)
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         unordered_map <int,int> mpp;
//         for(int i=0; i<nums2.size(); i++)
//             mpp[nums2[i]]=i;
//         for(int i=0; i<nums1.size(); i++){
//             int j=1;
//             while(mpp[nums1[i]]+j<nums2.size()){
//                 if(nums2[mpp[nums1[i]]+j]>nums2[mpp[nums1[i]]]){
//                     ans.push_back(nums2[mpp[nums1[i]]+j]);
//                     break;
//                 }
//                 j++;
//             }
//             if(mpp[nums1[i]]+j==nums2.size())
//                 ans.push_back(-1);
//         }
//         return ans;
//     }
// };