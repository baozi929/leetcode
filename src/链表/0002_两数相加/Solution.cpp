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
        if (!l1) return l2;
        if (!l2) return l1;

        int num = 0;
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        while (l1 && l2) {
            num = l1->val + l2->val + carry;
            prev->next = new ListNode(num % 10);
            prev = prev->next;
            carry = num / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* l3 = l1 ? l1 : l2;

        while (l3) {
            num = l3->val + carry;
            prev->next = new ListNode(num % 10);
            prev = prev->next;
            carry = num / 10;
            l3 = l3->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        ListNode* head = dummy->next;

        delete dummy;
        dummy = nullptr;

        return head;
    }
};