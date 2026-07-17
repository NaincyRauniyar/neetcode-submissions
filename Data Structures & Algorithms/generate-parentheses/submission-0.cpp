class Solution {
public:
void solve(int n,vector<string>&ans,string output,int total,int close,int open){
    if(open + close== total){
        ans.push_back(output);
        return;
    } 
    if(close<open){
        solve(n,ans,output+")",total,close+1,open);
    }
    if(open < n)
    solve(n,ans,output + "(",total,close,open+1);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output = "";
        int total = n*2;
        solve(n,ans,output,total,0,0);
        return ans;
    }
};
