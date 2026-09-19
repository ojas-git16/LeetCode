class Solution {
public:
    vector<string> ans;
    void func(string& s, int n, int cntop, int cntcl) {
        int sz = s.size();
        if (sz == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (cntop == n) {
            s.push_back(')');
            func(s, n, cntop, cntcl + 1);
        } 
        else {
            char p = s[sz - 1];
            if (p == ')'  && cntop == cntcl){
                s.push_back('(');
                func(s, n, cntop + 1, cntcl);
            }
            else{
                string s1 = s, s2 = s;
                s1.push_back('(');
                s2.push_back(')');
                func(s1, n, cntop + 1, cntcl);
                func(s2, n, cntop, cntcl + 1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "(";
        func(s, n, 1, 0);
        return ans;
    }
};