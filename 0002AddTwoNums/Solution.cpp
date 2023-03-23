#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* anchor = new ListNode();
        ListNode* head = anchor;
        int overflow = 0;
        while(l1 && l2) {
            ListNode* tmp = new ListNode( (l1->val+l2->val+overflow)%10);
            overflow = (l1 -> val + l2 -> val + overflow) / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            head -> next = tmp;
            head = head -> next;
        }
        while(l1) {
            ListNode* tmp = new ListNode( (l1->val+overflow) % 10 );
            overflow = (l1 -> val + overflow) / 10;
            head -> next = tmp;
            head = head -> next;
            l1 = l1 -> next;
        }
        while(l2) {
            ListNode* tmp = new ListNode( (l2->val+overflow) % 10 );
            overflow = (l2 -> val + overflow) / 10;
            head -> next = tmp;
            head = head -> next;
            l2 = l2 -> next;
        }
        if(overflow == 1) head -> next = new ListNode(1);
        return anchor -> next;
    }
};
