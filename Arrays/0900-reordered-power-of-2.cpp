class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1)
            return true;
        string s1=to_string(n);
        sort(s1.begin(),s1.end());
        
        for(int i=0; i<30; i++){
            string s2=to_string((int)pow(2,i));
            sort(s2.begin(),s2.end());
            if(s1==s2)
                return true;
            if(s1.size()<s2.size())
                return false;
        }
        return false;
    }
};