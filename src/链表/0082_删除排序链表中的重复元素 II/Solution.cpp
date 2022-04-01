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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while(prev->next && prev->next->next){
            if(prev->next->val == prev->next->next->val){
                ListNode* dupNode = prev->next;
                int dupVal = dupNode->val;
                while(dupNode && dupNode->val == dupVal){
                    prev->next = dupNode->next;
                    delete dupNode;
                    dupNode = prev->next;
                }
            }
            else{
                prev = prev->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};