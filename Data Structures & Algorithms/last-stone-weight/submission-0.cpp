class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     priority_queue<int> maxh;
      for(auto x:stones){
        maxh.push(x);
      }  
      while(maxh.size()>1){
        int x = maxh.top();maxh.pop();
        int y=maxh.top();maxh.pop();
       
       if(x != y) maxh.push(x-y);
        }
        if(maxh.size()) 
        return maxh.top();
        return 0;
    }
};
