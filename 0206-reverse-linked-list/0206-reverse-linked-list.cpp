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
    void reverseLL(ListNode* &head , ListNode* prev , ListNode* curr){
        //base case
        if(curr == NULL){
            head = prev;
            return;
        }

        ListNode* forward = curr -> next;
        reverseLL(head , curr , forward);
        curr -> next = prev;
    }
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        reverseLL(head , prev , curr);
        return head;
        // if(head == NULL || head -> next == NULL){
        //     return head;
        // }
            
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // while(curr != NULL){
        //     ListNode* forward = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = forward;
        // }
        // return prev;
    }
};