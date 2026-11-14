class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        // next samller element(index)
        stack<int > st;
        vector<int> nsi(n);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()>0) nsi[i]=st.top();
            else nsi[i]=n; // -1 no next smaller
            st.push(i);
        }
        // prev samller element(index)
        while(st.size()>0) st.pop();
        vector<int> psi(n);
        for(int i=0;i<n;i++){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()>0) psi[i]=st.top();
            else psi[i]=-1; // -1 no prev smaller
            st.push(i);
        }

        int maxarea=0;
        for(int i=0;i<n;i++){
            int h=arr[i];
            int w=nsi[i]-psi[i]-1;
            int a =h*w;
            maxarea=max(maxarea,a);
        }
        return maxarea;
        
    }
};