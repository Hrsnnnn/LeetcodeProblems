#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void DisplayLinkedList(ListNode* start, string TAG="TAG") {
    cout << TAG << ": ";
    while(start) {
        cout << start->val << " -> ";
        start = start->next;
    }
    cout << endl;
}

ListNode* initLinkedList(int arr[], int length) {
    ListNode* anchor = new ListNode(arr[0]);
    ListNode* boat = anchor;

    for(int i=1;i<length;i++) {
        ListNode* buffer = new ListNode(arr[i]);
        boat -> next = buffer;
        boat = boat -> next;
    }
    return anchor;
}

class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenStart = even;

        if(!head -> next || !head -> next -> next) return head;

        while(even != nullptr && even -> next != nullptr) {
            cout << odd->val << ", " << even->val << endl;
            DisplayLinkedList(odd, "odd");
            DisplayLinkedList(even, "even");
            DisplayLinkedList(head, "whole");
            DisplayLinkedList(evenStart, "wholeEven");
            odd -> next = even -> next;
            even -> next = even -> next -> next;
            odd -> next -> next = evenStart;
            odd = odd -> next;
            even = even -> next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 7, 9};
    int length = 5;

    ListNode* anchor = initLinkedList(arr, length);
    Solution sol;
    ListNode* res = sol.oddEvenList(anchor);
    DisplayLinkedList(res);
    return 0;
}

