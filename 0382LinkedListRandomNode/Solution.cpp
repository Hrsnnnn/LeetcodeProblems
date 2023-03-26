#include<iostream>
#include<random>

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
    ListNode* root;
    int length;
    Solution(ListNode* head) {
        ListNode* anchor = new ListNode(0);
        while(head) {
            ListNode* node = new ListNode(head -> val);
            anchor -> next = node;
            head = head -> next;
            anchor = anchor -> next;
            length += 1;
        }
        root = anchor -> next;
        return;
    }
    
    int getRandom() {
        int randInt = rand() % length;
        cout << rand() << " " << length << endl;
        ListNode* anchor = root;
        for(int i=0;i<randInt;i++) {
            anchor = anchor -> next;
        }
        return anchor->val;
    }
};

