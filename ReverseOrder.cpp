#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> &st){
    stack<int> helper;
    while(st.size()>0){
        cout<<st.top()<<" ";
        helper.push(st.top());
        st.pop();
    }
    cout<<endl;
    // put back element i st from helper
    while(helper.size()>0){
        st.push(helper.top());
        helper.pop();
     }
}

stack<int> reverse(stack<int>& st){
    stack<int> h1;
    stack<int> h2;
    while(st.size()){
        h1.push(st.top());
        st.pop();
    }
    while(h1.size()){
        h2.push(h1.top());
        h1.pop();
    }
    while(h2.size()){
        st.push(h2.top());
        h2.pop();
    }
    return st;
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    print(st);
    cout<<"After Reverse"<<endl;
    reverse(st);
    print(st);

}