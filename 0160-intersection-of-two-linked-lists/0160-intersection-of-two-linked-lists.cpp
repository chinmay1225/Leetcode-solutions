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
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        if(lenA > lenB){
            int diff = lenA - lenB;
            while(diff--){
                p1 = p1 -> next;
            }
        }else{
            int diff = lenB - lenA;
            while(diff--){
                p2 = p2 -> next;
            }
        }

        while(p1 && p2){
            if(p1 == p2){
                return p1;
            }

            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return NULL;
    }
};