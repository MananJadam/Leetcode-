class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || k==1)
            return head;

        ListNode dummy(0);
        dummy.next=head;

        ListNode *prevGroup=&dummy;

        while(true){

            // Find kth node
            ListNode *kth=prevGroup;

            for(int i=0;i<k && kth!=NULL;i++)
                kth=kth->next;

            if(kth==NULL)
                break;

            ListNode *groupNext=kth->next;

            // Reverse
            ListNode *prev=groupNext;
            ListNode *curr=prevGroup->next;

            while(curr!=groupNext){

                ListNode *nextNode=curr->next;

                curr->next=prev;

                prev=curr;

                curr=nextNode;
            }

            ListNode *temp=prevGroup->next;

            prevGroup->next=kth;

            prevGroup=temp;
        }

        return dummy.next;
    }
};