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
    ListNode* func(ListNode * ptr){
        if(ptr == NULL || ptr->next == NULL)
            return ptr;
        ListNode * temp = ptr->next;
        ListNode * newHead = func(ptr->next);
        temp->next = ptr;
        ptr->next = nullptr;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return func(head);
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL || head->next==NULL)
//             return head;
//         ListNode * temp = nullptr;
//         ListNode * ptr = head;
//         while(head!=NULL){
//             head = head->next;
//             ptr->next = temp;
//             temp = ptr;
//             ptr = head;
//         }
//         return temp;
//     }
// };