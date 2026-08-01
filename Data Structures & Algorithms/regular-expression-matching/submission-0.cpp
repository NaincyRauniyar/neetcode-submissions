class Solution {
public:
bool f(string s,string p){
    if(p.size() ==0){
        if(s.size() ==0) return true;
        return false;
    }
    int first_match = (!s.empty() && (s[0] == p[0] || p[0] =='.'));

    if(p.size()>= 2 && p[1] =='*'){
    bool not_take = f(s,p.substr(2));
    bool take =false;
    if(first_match)
        take = f(s.substr(1),p);
    
    return take||not_take;
    }
    else 
    return first_match && f(s.substr(1),p.substr(1));
}
    bool isMatch(string s, string p) {
       return f(s,p); 
    }
};
