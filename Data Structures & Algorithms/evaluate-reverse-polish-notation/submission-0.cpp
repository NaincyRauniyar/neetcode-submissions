class Solution {
public:
bool isop(string s){
    return (s=="+" || s=="-" || s=="/" || s=="*"); 
}
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto s: tokens){
            if(!isop(s)){
                st.push(stoi(s));
            }
            else { 
                int a= st.top();st.pop();
                int b =st.top();st.pop();

                if(s=="+")st.push(a+b);
                else if(s=="*")st.push(a*b);
                else if(s=="/")st.push(b/a);
                else st.push(b-a);
            }
        }
        return st.top();
    }
};
