class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int, int>> p(speed.size());
        for(int i = 0; i < speed.size(); i++){
            p[i].first = position[i];
            p[i].second = speed[i];
        }

        sort(p.begin(), p.end(), [](const auto& a, const auto& b){
            return b.first < a.first;
        });

        int curr = 0;
        float mx = 0;

        for(const auto& a : p){
            float time = 1.0 * (target - a.first) / a.second;
            if(time > mx) curr++;
            mx = max(mx, time);
        }
        return curr;
    }
};