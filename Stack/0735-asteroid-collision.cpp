class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        stack <int> st;
        for(int a : asteroids){
            bool alive = true;
            while(!st.empty() && st.top()>0 && a<0){
                if(st.top()>-a){
                    alive = false;
                    break;
                }
                else if(st.top()==-a){
                    st.pop();
                    alive = false;
                    break;
                }
                else
                    st.pop();
            }
            if(alive)
                st.push(a);
        }
        vector <int> ans(st.size(),0);
        int i = st.size()-1;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};