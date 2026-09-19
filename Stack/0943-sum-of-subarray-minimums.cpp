class Solution {
public:
    vector <int> ps(vector<int> v){
        vector <int> pse(v.size(),-1);
        stack <int> st;
        for(int i=0; i<v.size(); i++){
            while(!st.empty() && v[st.top()]>v[i])
                st.pop();
            if(!st.empty())     pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    vector <int> ns(vector<int> v){
        vector <int> nse(v.size(),v.size());
        stack <int> st;
        for(int i=v.size()-1; i>=0; i--){
            while(!st.empty() && v[st.top()]>=v[i])
                st.pop();
            if(!st.empty())     nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        long long MOD = 1e9 + 7;
        vector <int> nse = ns(arr);
        vector <int> pse = ps(arr);
        for(int i=0; i<arr.size(); i++){
            sum = sum + (1LL * (i-pse[i]) * (nse[i]-i) * arr[i]);
            sum = sum % MOD; 
        }
        return sum;
    }
};