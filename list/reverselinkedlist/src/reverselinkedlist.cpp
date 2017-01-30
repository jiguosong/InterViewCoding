/*
Reverse a singly linked list.

A linked list can be reversed either iteratively or recursively. Could you implement both?

 */

#include "reverselinkedlist.h"

ListNode<int> *reverselinkedlist::ReverseList(ListNode<int> *list)
{
    ListNode<int> *prev, *curr, *next;
    prev = nullptr;
    curr = list;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode<int> *reverselinkedlist::ReverseList_iter(ListNode<int> *list)
{
    if (!list || !(list->next)) return nullptr;
    ListNode<int> *p = ReverseList_iter(list->next);
    list->next->next = list;
    list->next = nullptr;
    return p;
}


