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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head1 = reverse(head);
        ListNode* temp = head1;
        int cnt = 1;
        if(head1 == NULL){
            return NULL;
        }
        if(n == 1){
            temp = head1;
            head1 = head1 -> next;
            delete temp;
        }else{
            ListNode* curr = head1;
            ListNode* prev = NULL;
            cnt = 1;

            while(cnt < n){
                prev = curr;
                curr = curr -> next;
                cnt++;
            }

            prev -> next = curr -> next;
            delete curr;
        }

        ListNode* ans = reverse(head1);
        return ans;
    }
};