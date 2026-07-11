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
    ListNode* getMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left , ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left != NULL && right != NULL){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }

        while(left!=NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }

        while(right!=NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        ans = ans -> next;
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        //get mid and break in two parts
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        //sort both lists
        left = sortList(left);
        right = sortList(right);

        //Merge both sorted list
        ListNode* result = merge(left , right);
        return result;
    }
};