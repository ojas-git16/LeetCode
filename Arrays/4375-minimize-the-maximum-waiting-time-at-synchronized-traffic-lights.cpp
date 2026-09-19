class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int time = -1;
        int penalty = 0;
        for(int x : lights)
            time = max(time, x);
        for(int i=0; i<arrivalTime.size(); i++){
            int penal = arrivalTime[i]%period;
            if(time <= penal)
                penalty = max(penalty , period - penal);
        }
        return penalty;
    }
};