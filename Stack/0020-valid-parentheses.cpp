class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        for(char x : s){
            if(x=='(' || x=='[' || x=='{')
                st.push(x);
            else if(st.size()!=0){
                if((x==')' && st.top() == '(') || (x=='}' && st.top() == '{') || (x==']' && st.top() == '['))
                    st.pop();
                else    return false;
            }
            else
                return false;
        }
        if(st.size()==0)
            return true;
        return false;
    }
};