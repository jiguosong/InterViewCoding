/*

*/

#include "partitionlist.h"

void partitionlist::dummy()
{
}

// TODO: need debug this
ListNode<int> *partitionlist::PartitionList(ListNode<int> *head, int k) {
    ListNode<int> *dummy1 = new ListNode<int>(1);
    ListNode<int> *dummy2 = new ListNode<int>(1);
    dummy1->next = head;
    dummy2->next = nullptr;

    ListNode<int> *prev, *curr, *curr2;
    curr = head;
    prev = dummy1;
    curr2 = dummy2;

    while(curr) {
        if(curr->data <= k) {
            curr2->next = curr;
            curr2 = curr2->next;
            prev->next = curr->next;
            curr = curr->next;
            curr2->next = nullptr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    curr2->next = dummy1->next;
    ListNode<int> *res = dummy2->next;
    delete dummy1;
    delete dummy2;
    return res;
}


