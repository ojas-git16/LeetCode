class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack <int> st;
        vector<int> ans;
        for(int i=temp.size()-1; i>=0; i--){
            while(!st.empty() && temp[st.top()]<=temp[i])
                st.pop();
            if(!st.empty() && temp[st.top()]>temp[i])
                ans.push_back(st.top()-i);
            else if(st.empty())
                ans.push_back(0);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};