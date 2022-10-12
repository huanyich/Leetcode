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
    void reorderList(ListNode* head) {
        // Time Complexity: O(n) Space Complexity: O(n)
        /* vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }

        int n = v.size();
        int left = 0;
        int right = n-1;

        while(left<right){
            v[left]->next = v[right];
            left++;
            if(left==right) break;
            v[right]->next = v[left];
            right--;
        }
        v[left]->next = NULL; */

        //idea:
        //divide the linked list into two part
        //reverse the second part
        //merge two array
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse the second part
        ListNode* second = reverse(slow);
        ListNode* first = head;
        ListNode* tmp = new ListNode();
        while(second->next){
            tmp = first->next;
            first->next = second;
            first = tmp;

            tmp = second->next;
            second->next = first;
            second = tmp;
        }




    }

    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* successor = NULL;

        while(node){
            successor = node->next;
            node->next = prev;
            prev = node;
            node = successor;
        }
        return prev;
    }



};
