class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
    int n = h.size();
    int maxi =0;
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && h[st.top()] > h[i]){
            int ele =st.top();
            st.pop();
            int nse = i;
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi, h[ele]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int nse =n;
        int ele =st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi, h[ele]*(nse-pse-1));
    }
    return maxi;
    }
};
