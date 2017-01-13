/*
    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include "buildtreefromsortedlist.h"

void buildtreefromsortedlist::dummy() 
{
}

TreeNode *buildtreefromsortedlist::sortedListToBST(ListNode<int> *head)
{

    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return new TreeNode(head->data);

    ListNode<int> *fast, *slow, *prev;
    fast = slow = prev = head;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(slow->data);
    fast = slow->next;
    prev->next = nullptr;
    if(head != slow) root->left = sortedListToBST(head);
    root->right = sortedListToBST(fast);

    return root;
}


