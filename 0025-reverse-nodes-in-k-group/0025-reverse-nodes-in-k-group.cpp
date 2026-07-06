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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;
        int cnt = 0;
        while(cnt < k && temp != NULL){
            temp = temp -> next;
            cnt++;
        }

        if(cnt < k){
            return head;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        cnt = 0;
        while(cnt < k && curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next != NULL){
            head -> next = reverseKGroup(next , k);
        }

        return prev;
    }
};