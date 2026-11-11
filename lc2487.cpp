/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;  
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp=head;
        while(temp){
            while(st.size()>0 && (st.top())->val < temp->val){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        temp=dummy;
        while(st.size()>0){
            ListNode* top=st.top();
            st.pop();
            temp->next=top;
            temp=top;
        }
        temp->next=NULL;
        return reverse(dummy->next);
        
    }
};