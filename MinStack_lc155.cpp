<<<<<<< HEAD
// class MinStack {
//     stack<int> st;
//     stack<int> minst;
// public:
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         st.push(value);
//         if(minst.size()==0 or value < minst.top()) minst.push(value);
//         else minst.push(minst.top());
        
//     }
    
//     void pop() {
//         st.pop();
//         minst.pop();
        
//     }
    
//     int top() {
//         return st.top();
        
//     }
    
//     int getMin() {
//         return minst.top();
        
//     }
// };
class MinStack {
    stack<long long> st;
    long long mn;
public:
    MinStack() {
        mn=LLONG_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(st.size() == 0){
            st.push(value);
            mn=value;
        }
        else{
            if(value>=mn) st.push(value);
            else{ // new min found
                st.push(value + (value - mn));
                mn=value;
            }
        }
        
    }
    
    void pop() {
        if(st.top()<mn){
            long long oldmn=2*mn-st.top();
            mn=oldmn;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mn){
            return mn;
        }
        else return st.top();

    }
    
    int getMin() {
        return mn;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
=======
// class MinStack {
//     stack<int> st;
//     stack<int> minst;
// public:
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         st.push(value);
//         if(minst.size()==0 or value < minst.top()) minst.push(value);
//         else minst.push(minst.top());
        
//     }
    
//     void pop() {
//         st.pop();
//         minst.pop();
        
//     }
    
//     int top() {
//         return st.top();
        
//     }
    
//     int getMin() {
//         return minst.top();
        
//     }
// };
class MinStack {
    stack<long long> st;
    long long mn;
public:
    MinStack() {
        mn=LLONG_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(st.size() == 0){
            st.push(value);
            mn=value;
        }
        else{
            if(value>=mn) st.push(value);
            else{ // new min found
                st.push(value + (value - mn));
                mn=value;
            }
        }
        
    }
    
    void pop() {
        if(st.top()<mn){
            long long oldmn=2*mn-st.top();
            mn=oldmn;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mn){
            return mn;
        }
        else return st.top();

    }
    
    int getMin() {
        return mn;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
>>>>>>> 687340e5914f02042b46f6c119cf13facd2f1546
 */