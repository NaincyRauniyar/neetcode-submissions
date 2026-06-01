class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int maxi =0;
        for(int i=0;i<n;i++){
            int area=0;
            for(int j = n-1;j>=0;j--){
               maxi = max(maxi, min(h[i],h[j]) * (j-i));//h*widhth
        }
        }
        return maxi;
    }
};
