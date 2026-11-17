class Solution {
  public:
    int op(int& a,int& b,string& optr){
            if(optr=="+") return a+b;
            else if(optr=="-") return a-b;
            else if(optr=="*") return a*b;
            else if(optr=="^") return pow(a,b);
            else{
                return floor(float (a)/b);
            }
        }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        stack<int> st;
        int n =arr.size();
        for(int i =n-1;i>=0;i--){
            string s=arr[i];
            if(s=="+" or s=="-" or s=="/" or s=="^" or s=="*"){ // work
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(op(a,b,s));
            }
            else st.push(stoi(s));
        }
        return st.top();
            
    }
};
