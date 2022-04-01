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
        ListNode* curNode = head;
        while(curNode && curNode->next){
            if(curNode->val == curNode->next->val){
                ListNode* toDelete = curNode->next;
                curNode->next = toDelete->next;
                delete toDelete;
            }
            else{
                curNode = curNode->next;
            }   
        }

        return head;
    }
};