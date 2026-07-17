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
private:
    int getLen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head -> next == NULL){
            return NULL;
        }
        int len = getLen(head);
        int middle = len/2;

        //node before middle
        ListNode* prev = head;
        for(int i=1; i< middle; i++){
            prev = prev -> next;
        }

        ListNode* nodeToDelete = prev -> next;
        prev -> next = nodeToDelete -> next;

        return head;
    }
};