class Solution {
public:
    int countRotations(string s, int k) {
        int rot = s.size();
        int ans = 0;
        for(int i=0; i<rot; i++){
            int cnt = 0;
            for(int j=i; j<rot+i-1; j++){
                if(s[j%rot]==s[(j+1)%rot])
                    cnt++;
            }
            if(cnt == k)
                ans++;
        }
        return ans;
    }
};