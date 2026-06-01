class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for( auto c:s){
            if(isalnum(c))
            news += tolower(c);
        }
         string rev = string(news.rbegin(),news.rend());
        return news == rev;
    }
};
