class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        if(n==0 || n==1)        return n;
        vector <pair<int,int>> cars;
        for(int i=0; i<n; i++)
            cars.push_back({position[i],speed[i]});
        sort(cars.rbegin(),cars.rend());
        stack <double> st;
        for(auto car : cars){
            int pos = car.first;
            int spd = car.second;
            double time = (double)(target - pos) / spd;
            if(st.empty() || time > st.top())
                st.push(time);
        }
        return st.size();
    }
};