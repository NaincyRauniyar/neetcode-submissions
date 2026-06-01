class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //sliding window
      int n= prices.size();
       int ans =0;
       for(int i=0;i<n;i++){
        int buy = prices[i];
        for(int j=i+1;j<n;j++){
            int sell = prices[j];
            ans = max(ans, sell-buy);
        }
       }
       return ans;
    }
};
