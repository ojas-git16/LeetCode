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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * ptr = head;
        if(head == NULL || head->next == NULL)
            return head;
        int cnt = 1;
        while(ptr->next){
            ptr = ptr->next;
            cnt++;
        }
        
        k = k%cnt;
        if(k==0)
            return head;

        ptr->next = head;
        int x = cnt-k-1;

        ListNode* back = head;
        while(x--){
            back = back->next;
        }

        ListNode* newHead = back->next;
        back->next = NULL;
        return newHead;
    }
};