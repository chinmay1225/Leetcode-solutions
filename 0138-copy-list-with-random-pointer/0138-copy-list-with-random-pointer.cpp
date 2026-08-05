/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head , Node* &tail , int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead , cloneTail ,  temp -> val);
            temp = temp -> next;
        }
        
        Node* cloneNode = cloneHead;
        Node* originalNode = head;

        unordered_map< Node* , Node*> oldToNew;

        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        cloneNode = cloneHead;
        originalNode = head;

        while(originalNode != NULL){
            cloneNode -> random = oldToNew[originalNode -> random];
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }

        return cloneHead;
    }
};