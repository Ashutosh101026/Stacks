class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            // pop mark push
            while(st.size() > 0 && st.top() <= arr[i]){ 
                st.pop();
                ans[i]++;
            }
            if(st.size()!=0) ans[i]++;
            st.push(arr[i]);
        }
        return ans;
        
    }
};