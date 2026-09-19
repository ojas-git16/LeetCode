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
        ListNode * bwd = nullptr;
        ListNode * fwd = ptr->next;
        while(ptr){
            ptr->next = bwd;
            bwd = ptr;
            ptr = fwd;
            if(fwd)
                fwd = fwd->next;
        }
        return bwd;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        ListNode * fast = head;
        ListNode * bef = nullptr;
        while(fast){
            ListNode * slow = fast;

            ListNode* kth = fast;
            for(int i = 1; i < k; i++) {
                if(kth == NULL || kth->next == NULL)
                    return head;      // Less than k nodes left
                kth = kth->next;
            }
            fast = kth->next;
            kth->next = nullptr;
            ListNode * newhead = reverseLL(slow);
            if(bef)
                bef->next = newhead;
            else
                head = newhead;
            slow->next = fast;
            bef = slow;
            slow = fast;
        }
        return head;
    }
};