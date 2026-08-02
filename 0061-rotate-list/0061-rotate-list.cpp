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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;


        ListNode *temp=head;
        vector<int>nums;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        k=k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=nums[i];
            i++;
            temp=temp->next;
        }

        return head;
 
    }
};