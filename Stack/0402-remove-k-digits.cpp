class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char c : num){
            while(k>0 && !s.empty() && s.back()>c){
                s.pop_back();
                k--;
            }
            s.push_back(c);
        }
        while(k>0){
            s.pop_back();
            k--;
        }
        int i=0;
        while(i<s.size() && s[i]=='0')
            i++;
        if(i == s.size())
            return "0";
        return s.substr(i);
    }
};