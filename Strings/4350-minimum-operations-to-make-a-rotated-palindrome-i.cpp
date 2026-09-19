class Solution {
public:
    int cost(char a, char b){
        int ans = INT_MAX;
        for(char i = 'a'; i<='z'; i++){
            int costA = (i-a+26)%26;
            int costB = (i-b+26)%26;
            ans = min(ans,costA+costB);
        }
        return ans;
    }
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for(int k=0; k<n; k++){
            int curr = k;
            for(int i=0; i<n/2; i++){
                char left = s[(i+k)%n];
                char right = s[(n-1-i+k)%n];
                curr += cost(left, right);
            }
            ans = min(ans,curr);
        }
        return ans;
    }
};