/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* cycleDetection(ListNode* head){
        if(head == NULL){
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast -> next != NULL ){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* intersection = cycleDetection(head);
        if(intersection == NULL){
            return NULL;
        }

        while(slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }

        return slow;
    }
};