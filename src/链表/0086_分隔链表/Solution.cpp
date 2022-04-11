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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerList = new ListNode();
        ListNode* largerList = new ListNode();
        ListNode* curNode1 = smallerList;
        ListNode* curNode2 = largerList;

        while(head != nullptr){
            if(head->val < x){
                curNode1->next = head;
                curNode1 = curNode1->next;
            }
            else{
                curNode2->next = head;
                curNode2 = curNode2->next;
            }
            head = head->next;
        }

        // tail of larger list
        curNode2->next = nullptr;
        // tail of smaller list
        curNode1->next = largerList->next;
        head = smallerList->next;

        delete smallerList;
        delete largerList;

        return head;
    }
};