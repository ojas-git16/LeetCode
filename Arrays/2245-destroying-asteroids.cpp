class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int a:asteroids)
        {
            if(m<a)
                return false;
            m+=a;
        }
        return true;
    }
};