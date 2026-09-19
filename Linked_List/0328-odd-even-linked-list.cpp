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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * head1 = head;
        ListNode * head2 = head->next;

        ListNode * ptr1 = head1;
        ListNode * ptr2 = head2;

        while(true){
            bool link = false;
            if(ptr1->next && ptr1->next->next){
                ptr1->next = ptr1->next->next;
                ptr1 = ptr1->next;
                link = true;
            }
            if(ptr2->next && ptr2->next->next){
                ptr2->next = ptr2->next->next;
                ptr2 = ptr2->next;
                link = true;
            }
            if(link == false)
                break;
        }
        ptr2->next = NULL;
        ptr1->next = head2;
        return head1;
    }
};