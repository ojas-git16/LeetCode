class Solution {
public:
    bool isPalindrome(string s) {
        string m="";
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
                m.push_back(s[i]);
                j++;}
            else if(s[i]>='A' && s[i]<='Z'){
                m.push_back(s[i]+32);
                j++;}
        }
        string l=m;
        reverse(m.begin(),m.end());
        if(l==m)
            return true;
        return false;
    }
};