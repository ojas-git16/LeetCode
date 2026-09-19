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
// TC - O(2n), SC - O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* ptr = head;
        while (ptr) {
            Node* temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = temp->next;
        }
        ptr = head;
        while (ptr) {
            if (ptr->random == nullptr)
                ptr->next->random = nullptr;
            else
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node* newhead = head->next;
        Node* copy = newhead;

        while (ptr) {
            ptr->next = copy->next;
            ptr = ptr->next;
            if (ptr) {
                copy->next = ptr->next;
                copy = copy->next;
            }
        }
        return newhead;
    }
};

// TC - O(2n), SC - O(n)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (head == NULL)
//             return NULL;

//         unordered_map<Node*, Node*> mp;

//         Node* ptr = head;
//         Node* newhead = new Node(ptr->val);
//         Node* newptr = newhead;

//         mp[ptr] = newptr; // Store mapping

//         while (ptr->next) {
//             ptr = ptr->next;
//             Node* temp = new Node(ptr->val);
//             newptr->next = temp;
//             newptr = temp;
//             mp[ptr] = newptr;
//         }

//         ptr = head;
//         newptr = newhead;
//         while(ptr){
//             ptr->random == nullptr ? newptr->random = nullptr :
//             newptr->random = mp[ptr->random]; ptr = ptr->next; newptr =
//             newptr->next;
//         }
//         return newhead;
//     }
// };