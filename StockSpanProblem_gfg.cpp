class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] <= arr[i]) {
                    st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            ans[i]=i-ans[i];
        }
        return ans;
    }
};