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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int middle=cnt/2;
        
        temp=head;
        for(int i=1; i<middle;i++){
            temp=temp->next;
            
        }
        ListNode *del=temp->next;
        temp->next=del->next;
        delete del;

        return head;
        
    }
};