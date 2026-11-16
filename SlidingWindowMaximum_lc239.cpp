// m1 brute force TLE occour tc: o(n*k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans(n-k+1,INT_MIN);
        for(int i=0;i<n-k+1;i++){
            for(int j=i;j<i+k;j++){
                ans[i]=max(ans[i],arr[j]);
            }
        }
        return ans;
        
    }
};

// m2 stacks tc:o(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> nge(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()] <= arr[i]) 
                st.pop();
            if(st.size()>0) nge[i]=st.top();
            st.push(i);
        }
        vector<int> ans(n-k+1);
        int j;
        for(int i=0;i<n-k+1;i++){
            if(j < i) j=i;
            while(nge[j] != -1 && nge[j] < i+k) 
                j=nge[j];
            ans[i]=arr[j];  // marked the max in window 
        }
        return ans;
        
    }
};