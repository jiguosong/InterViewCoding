/*
    Sort a linked list in O(n log n) time using constant space complexity.
*/

#include "sortlist.h"

void sortlist::dummy()
{
}


ListNode<int> *merge(ListNode<int> *l1, ListNode<int> *l2)
{
    ListNode<int> *dummy = new ListNode<int>(-1);
    ListNode<int> *curr = dummy;

    while(l1 && l2) {
        if(l1->data < l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if(l1) curr->next = l1;
    else if(l2) curr->next = l2;

    ListNode<int> *res = dummy->next;
    delete dummy;
    return res;
}


ListNode<int> *sortlist::SortList(ListNode<int> *head)
{
    if (head == nullptr || head->next == nullptr) return head;
    ListNode<int> *fast, *slow, *prev;
    fast = slow = prev = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    return merge(SortList(head), SortList(slow));
}


