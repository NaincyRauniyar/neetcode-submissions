class Solution {
public:
bool f(int i,int j,int k,string s1, string s2, string s3,vector<vector<vector<int>>> &dp){
    int n1=s1.size();
     int n2=s2.size();
      int n3=s3.size();
      //base case
      if(k == n3 && (i==n1 && j==n2)) return true;
      if(dp[i][j][k] != -1) return dp[i][j][k];

      if(i<n1 && s1[i] == s3[k]){
        if(f(i+1,j,k+1,s1,s2,s3,dp))
        return dp[i][j][k] = true;
      }

      if(j<n2 && s2[j] == s3[k]){
        if(f(i,j+1,k+1,s1,s2,s3,dp))
        return dp[i][j][k] =  true;
      }
      return dp[i][j][k] =false;
}
    bool isInterleave(string s1, string s2, string s3) {
         int n1=s1.size();
     int n2=s2.size();
      int n3=s3.size();
      vector<vector<vector<int>>> dp (n1+1, vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return f(0,0,0,s1,s2,s3,dp);
    }
};