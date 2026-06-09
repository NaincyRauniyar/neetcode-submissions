class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        //90 degree swap and rotate
        int n = m.size();
        int s = m[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<s;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(m[i].begin(),m[i].end());
        }
    }
};
