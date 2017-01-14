/*

Given a linked list and two values v1 and v2. Swap the two nodes in the linked list with values v1 and v2. It's guaranteed there is no duplicate values in the linked list. If v1 or v2 does not exist in the given linked list, do nothing.
Notice

You should swap the two nodes with values v1 and v2. Do not directly swap the values of the two nodes.

*/

#include "swaptwonodes.h"

void swaptwonodes::dummy() 
{
}

ListNode<int> *swaptwonodes::SwapTwoNode(ListNode<int> *head, int v1, int v2)
{
    if(head == nullptr) return head;
    if(v1 == v2) return head;

    ListNode<int> *c1, *p1, *c2, *p2;
    p1 = p2 = nullptr;
    c1 = c2 = head;

    while(c1 && c1->data != v1) {
        p1 = c1;
        c1 = c1->next;
    }

    while(c2 && c2->data != v2) {
        p2 = c2;
        c2 = c2->next;
    }

    if(!c1 || !c2) return head;

    if(p1) p1->next = c2;
    else head = c2;

    if(p2) p2->next = c1;
    else head = c1;

    ListNode<int> *tmp = c2->next;
    c2->next = c1->next;
    c1->next = tmp;

    return head;
}