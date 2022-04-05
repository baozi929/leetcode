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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev  = dummy;
        ListNode* firstNode = nullptr;
        ListNode* nextNode = nullptr;

        while(prev->next && prev->next->next){
            nextNode = prev->next->next->next;
            firstNode = prev->next;
            prev->next = firstNode->next;
            prev->next->next = firstNode;
            prev->next->next->next = nextNode;
            prev = prev->next->next;
        }

        ListNode* retHead = dummy->next;

        delete dummy;
        dummy = nullptr;

        return retHead;
    }
};