class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector <vector<int>> ans;
        unordered_set <int> st;
        for(int x : nums){
            if(x >= lower && x <= upper)
                st.insert(x);
        }
        int start = -1, end = -1;
        for(int x = lower; x <= upper; x++){
            if(st.find(x) == st.end()){
                if(start == -1)
                    start = x;
                else
                    end = x;
            }
            else{
                if(start != -1 && end != -1)
                    ans.push_back({start,end});
                else if(start != -1 && end == -1)
                    ans.push_back({start,start});
                start = -1;
                end = -1;
            }
        }
        if(start != -1) {
            if(end != -1)
                ans.push_back({start, end});
            else
                ans.push_back({start, start});
        }
        return ans;
    }
};