#ifndef reverselinkedlist_H_
#define reverselinkedlist_H_

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "List.h"

class reverselinkedlist {
public:
	ListNode<int> *ReverseList(ListNode<int> *list);
	ListNode<int> *ReverseList_iter(ListNode<int> *list);
private:

};

#endif
