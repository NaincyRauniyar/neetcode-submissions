class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //base case
        if(s1.size()>s2.size()) return false;

        vector<int>cnt1(26,0);
        vector<int>cnt2(26,0);

        for(int i=0;i<s1.size();i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }

        int match =0;
        for(int i=0;i<26;i++){
            if(cnt1[i]==cnt2[i])
            match++;
        }
        int l=0;
        for(int r=s1.length();r<s2.size();r++){
            if(match ==26){
                return true;
            }

            int ind = s2[r]-'a';
            cnt2[ind]++;
            if(cnt1[ind]==cnt2[ind])
            match++;
            else if(cnt1[ind]+1 == cnt2[ind])
            match--;

            ind = s2[l]-'a';
            cnt2[ind]--;
             if(cnt1[ind]==cnt2[ind])
            match++;
            else if(cnt1[ind]-1 == cnt2[ind])
            match--;
            l++;
        }
        return match ==26;
    }
};
