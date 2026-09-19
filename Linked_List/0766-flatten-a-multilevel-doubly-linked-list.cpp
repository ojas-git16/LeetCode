/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)  return head;
        Node * ptr = head;
        while(ptr){
            if(ptr->child){
                Node * nextptr = ptr->next;
                Node * childlist = flatten(ptr->child);

                ptr->next = childlist;
                childlist->prev = ptr;

                ptr->child = nullptr;
                Node* temp = childlist;
                while(temp->next)
                    temp = temp->next;
                temp->next = nextptr;
                if(nextptr)
                    nextptr->prev = temp;
            }
            ptr = ptr->next;
        }
        return head;
    }
};