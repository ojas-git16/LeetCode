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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1 = l1;
        int cnt1=1, cnt2=1;
        while(temp1->next){
            temp1 = temp1->next;
            cnt1++;
        }
        ListNode * temp2 = l2;
        while(temp2->next){
            temp2 = temp2->next;
            cnt2++;
        }
        ListNode * ptr = l1;
        ListNode * prev = l1;
        if(cnt1<cnt2)
            ptr = l2;
        
        int carry = 0;
        temp1 = l1;
        temp2 = l2;
        while(ptr){
            int x = carry;
            if(temp1){
                x += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                x += temp2->val;
                temp2 = temp2->next;
            }
            ptr->val = x%10;
            carry = x/10;
            prev = ptr;
            ptr = ptr->next;
        }
        if(carry)
            prev->next = new ListNode(1);
        return (cnt1>=cnt2) ? l1 : l2;
    }
};