class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector <vector <int>> ans;
        for(int i=0; i<r; i++){
            vector <int> v;
            int el=1;
            v.push_back(1);
            for(int j=i; j>=1; j--){
                el*=j;
                el/=(i-j+1);
                v.push_back(el);
            }
            ans.push_back(v);
        }
        return ans;
    }
};