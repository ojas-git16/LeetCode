class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = requests[0];
        for(int i=0; i<requests.size()-1; i++){
            int x = requests[i] - requests[i+1];
            if(x>=0)       ans+=x;
            else      ans+=-x;
        }
        return ans;
    }
};