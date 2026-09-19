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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* ptr = new ListNode();
        ListNode* head = ptr;
        while (left && right) {
            if (left->val > right->val) {
                ListNode* temp = new ListNode(right->val);
                ptr->next = temp;
                ptr = ptr->next;
                right = right->next;
            } else {
                ListNode* temp = new ListNode(left->val);
                ptr->next = temp;
                ptr = ptr->next;
                left = left->next;
            }
        }
        while (left) {
            ptr->next = new ListNode(left->val);
            ptr = ptr->next;
            left = left->next;
        }

        while (right) {
            ptr->next = new ListNode(right->val);
            ptr = ptr->next;
            right = right->next;
        }
        return head->next;
    }
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* mid = findmid(head);
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = NULL;
        lefthead = mergeSort(lefthead);
        righthead = mergeSort(righthead);

        return merge(lefthead, righthead);
    }
    ListNode* sortList(ListNode* head) { return mergeSort(head); }
};