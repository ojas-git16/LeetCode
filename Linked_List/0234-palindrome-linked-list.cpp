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
    ListNode * reverseLL(ListNode * ptr){
        if(ptr->next == NULL || ptr == NULL)
            return ptr;

        ListNode * temp = ptr->next;
        ListNode * newHead = reverseLL(ptr->next);
        temp->next = ptr;
        ptr->next = NULL;
        return newHead;        
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        if(head->next->next == NULL){
            if(head->val == head->next->val)
                return true;
            return false;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newHead = reverseLL(slow->next);
        while(newHead){
            if(newHead->val != head->val)
                return false;
            newHead = newHead->next;
            head = head->next;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack <int> st;
//         ListNode * temp = head;
//         while(temp){
//             st.push(temp->val);
//             temp = temp->next;
//         }
//         temp = head;
//         while(temp){
//             if(temp->val == st.top()){
//                 st.pop();
//                 temp = temp->next;
//                 continue;
//             }
//             break;

//         }
//         if(temp == NULL)
//             return true;
//         return false;
//     }
// };