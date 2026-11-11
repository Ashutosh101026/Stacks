// method 1 nested loops
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    ans[i]=arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};
//methiod 2
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            // pop mark push
            while(st.size() > 0 && st.top() <= arr[i]) 
                st.pop();
            if(st.size()==0) ans[i]=-1;
            else ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};