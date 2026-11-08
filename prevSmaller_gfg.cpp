class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {

                    // Remove elements smaller than or equal to current
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

                    // Find previous greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }

                    // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};