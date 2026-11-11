#include<iostream>
#include<stack>
using namespace std;
void printTopToBottom(stack<int>& st){
    stack<int> helper;
    while(st.size() > 0){
        cout<<st.top()<<" ";
        helper.push(st.top());
        st.pop();
    }
    // put back elements from helper to st
    while(helper.size() > 0){
        st.push(helper.top());
        helper.pop();
    }
    cout<<endl;
}

void printBottomToTop(stack<int>& st){
    stack<int> helper;
    while(st.size() > 0){
        helper.push(st.top());
        st.pop();
    }
    // put back elements from helper to st
    while(helper.size() > 0){
        cout<<helper.top()<<" ";
        st.push(helper.top());
        helper.pop();
    }
    cout<<endl;
}

void push(int idx, int val, stack<int>& st){
    stack<int> helper;
    while(st.size() > idx){
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    // helper to stack
    while(helper.size() > 0){
        st.push(helper.top());
        helper.pop();
    }
}

void pop(int idx, stack<int>& st){
    
}

int get(int idx, stack<int>& st){
    
}

int main(){
    stack<int> st;
    st.push(18); st.push(33);
    st.push(1); st.push(45);
    st.push(7);

    // printTopToBottom(st);
    printBottomToTop(st);
    push(2,99,st);
    printBottomToTop(st);
}