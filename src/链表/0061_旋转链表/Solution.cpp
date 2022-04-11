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
        if(!head || !head->next || k == 0){
            return head;
        }
        int rotateK = k % countOfListNode(head);

        if(rotateK == 0){
            return head;
        }
        else{
            return innerRotateRight(head, rotateK);
        }
    }

private:
    int countOfListNode(ListNode* head){
        int countOfListNode = 0;
        while(head){
            countOfListNode++;
            head = head->next;
        }
        return countOfListNode;
    }
    ListNode* innerRotateRight(ListNode* head, int k){
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i < k; i++){
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;
        head = dummy->next;
        delete dummy;

        return head;
    }
};