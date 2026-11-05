class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1) return false;
        stack<char> st;
        for(char ch : s){
            if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
            else{ // ch is closing bracket
                if(st.size()==0) return false;
                if(ch==')' && st.top()=='(') st.pop();
                else if(ch==']' && st.top()=='[') st.pop();
                else if(ch=='}' && st.top()=='{') st.pop();
                else return false;
            }
        }
        return (st.size()==0);
        
    }
};