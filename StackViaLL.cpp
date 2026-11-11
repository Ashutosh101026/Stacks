#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};

class MyStack{
    Node* head;
    Node* tail;
    int length;
    public:
    MyStack(){
        head=tail=NULL;
        length=0;
    }
    void push(int val){
        Node* n=new Node(val);
        n->next=head;
        head=n;
        length++;

    }
    void pop(){
        if(length==0){
            cout<<"stack is empty"<<endl;
            return;
        }
        Node* tobedeleted=head;
        head=head->next;
        delete tobedeleted;
        length--;

    }
    int get(){
        if(length==0){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int size(){
        return length;
    }

    void print(){
        Node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.push(50);

    st.print();

}