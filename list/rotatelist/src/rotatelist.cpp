/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include "rotatelist.h"

void rotatelist::dummy() {
}

ListNode<int> *rotatelist::RotateList(ListNode<int> *head, int k) {
    if(head == nullptr) return nullptr;

    ListNode<int> *slow, *fast;
    slow = fast = head;
    int len = 0;
    while(fast) {
        fast = fast->next;
        ++len;
    }

    k = k%len;
    fast = head;

    while(k-- && fast) fast = fast->next;
    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    fast = slow->next;
    slow->next = nullptr;

    return fast;
}


