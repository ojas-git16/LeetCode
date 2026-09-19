class Solution {
public:
    vector <int> ng(vector<int> v){
        stack <int> st;
        vector <int> ans(v.size(),v.size());
        for(int i=v.size()-1; i>=0; i--){
            while(!st.empty() && v[st.top()]<=v[i])
                st.pop();
            if(!st.empty())     ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> pg(vector<int> v){
        stack <int> st;
        vector <int> ans(v.size(),-1);
        for(int i=0; i<v.size(); i++){
            while(!st.empty() && v[st.top()]<v[i])
                st.pop();
            if(!st.empty())     ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> ns(vector<int> v){
        stack <int> st;
        vector <int> ans(v.size(),v.size());
        for(int i=v.size()-1; i>=0; i--){
            while(!st.empty() && v[st.top()]>=v[i])
                st.pop();
            if(!st.empty())     ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> ps(vector<int> v){
        stack <int> st;
        vector <int> ans(v.size(),-1);
        for(int i=0; i<v.size(); i++){
            while(!st.empty() && v[st.top()]>v[i])
                st.pop();
            if(!st.empty())     ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector <int> nge = ng(nums);
        vector <int> pge = pg(nums);
        vector <int> nse = ns(nums);
        vector <int> pse = ps(nums);
        long long sum=0;
        for(int i=0; i<nums.size(); i++)
            sum = sum + (1LL*(i-pge[i])*(nge[i]-i)*nums[i]) - (1LL*(i-pse[i])*(nse[i]-i)*nums[i]);
        return sum;
    }
};