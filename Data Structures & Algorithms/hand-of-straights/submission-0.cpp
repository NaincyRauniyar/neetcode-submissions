class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n= hand.size();
        if(n%groupSize != 0) return false;

        unordered_map<int,int> cnt;
        for(auto x: hand)
            cnt[x]++;

            priority_queue<int,vector<int>, greater<int>> minH;
            for(auto &pair:cnt)
            minH.push(pair.first);

            while(!minH.empty()){
                int first = minH.top();

                for(int i=first;i<first+groupSize;i++){
                    if(cnt.find(i) == cnt.end()) return false;
                    cnt[i]--;

                    if(cnt[i] ==0){
                        if(i != minH.top()) return false;
                        minH.pop();
                    }
                }
            }
            return true;
    }
};
