class Solution {
  public:
    string postToInfix(string &s) {
        // code here
        stack<string> st;
        for(char ch : s){
            if(ch=='+' or ch=='-' or ch=='*' or ch=='/' or ch=='%' or ch=='^'){
                string b=st.top();
                st.pop();
                string a=st.top();
                st.pop();
                st.push("(" + a + string(1,ch) + b + ")");
            }
            else{
                st.push(string(1,ch));
            }
        }
        return st.top();
    }
};
