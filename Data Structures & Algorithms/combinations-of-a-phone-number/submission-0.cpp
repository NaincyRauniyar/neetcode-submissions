class Solution {
public:
vector<string> res;
vector<string> dToc ={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

void backtrack(int i,string curstr,string &digit){
    if(curstr.size() == digit.size()){
        res.push_back(curstr);
        return;
    }
    string chars = dToc[digit[i]-'0'];
    for(char c: chars){
        backtrack(i+1,curstr+c,digit);
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        backtrack(0,"",digits);
        return res;
    }
};
