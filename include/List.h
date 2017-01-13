/*
 * Node.h
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#ifndef LIST_NODE_H_
#define LIST_NODE_H_

#include <iostream>
#include <random>

using namespace std;

/*
 *
 *    This is the list node object
 *
 * */

template<class T>
class ListNode {
public:
    ListNode();

    ListNode(const T &item, ListNode<T> *ptrnetxt = NULL);

    T data;

    // access the next node
    ListNode<T> *NextNode();

    void print_list();

    // modify methods
    void InsertAfter(ListNode<T> *p);

    ListNode<T> *DeleteAfter();

    ListNode<T> *GetNode(const T &item, ListNode<T> *nextptr = NULL);

//private:  // I do not like this to be private
    ListNode<T> *next;
};

template<class T>
ListNode<T>::ListNode() {
    next = nullptr;
}

template<class T>
ListNode<T>::ListNode(const T &item, ListNode<T> *ptrnext) {
    this->data = item;
    this->next = ptrnext;
}

template<class T>
ListNode<T> *ListNode<T>::NextNode() {
    return this->next;
}

template<class T>
void ListNode<T>::print_list() {
    ListNode<int> *tmp = this;
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->NextNode();
    }
    cout << endl;
}

template<class T>
void ListNode<T>::InsertAfter(ListNode<T> *p) {
    p->next = this->next;
    this->next = p;
}

template<class T>
ListNode<T> *ListNode<T>::DeleteAfter() {
    ListNode<T> *tmp = next;
    if (next != NULL)
        next = next->next;
    return tmp;
}

template<class T>
ListNode<T> *GetNode(const T &item, ListNode<T> *nextptr = NULL) {
    ListNode<T> *newnode; // Local ptr for new node
    newnode = new ListNode<T>(item, nextptr);
    if (newnode == NULL) {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
    return newnode;
}

/*
 *
 *    This is the list object
 *
 * */

template<class T>
class List {
public:
    List();

    List(unsigned int list_sz, T __lower, T __upper) :
            length(list_sz), head(nullptr), lower(__lower), upper(__upper) {
        head = GenerateList();
    }

    ~List() { }

    ListNode<T> *head;
private:
    T lower;
    T upper;

    unsigned int length;

    ListNode<T> *GenerateList();

    ListNode<T> *Generate_List_Helper(ListNode<T> *head, int listLen, T low,
                                      T high);

    T getRandom();
};


template<class T>
List<T>::List() :
        length(0), head(nullptr), lower(0), upper(0) {
};

template<class T>
T List<T>::getRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(this->lower, this->upper);
    return dist(gen);
}

template<class T>
ListNode<T> *List<T>::Generate_List_Helper(ListNode<T> *head, int listLen,
                                           T lower, T upper) {
    if (head == nullptr || listLen == 0)
        return head;

    T item = getRandom();

    head->next = GetNode(item);
    --listLen;
    return Generate_List_Helper(head->next, listLen, lower, upper);
}

template<class T>
ListNode<T> *List<T>::GenerateList() {
    T item = getRandom();

    ListNode<T> *head = GetNode(item);
    Generate_List_Helper(head, this->length - 1, this->lower, this->upper);
    return head;
}


template<class T>
ListNode<T> *merge(ListNode<T> *l1, ListNode<T> *l2)
{
    ListNode<T> *dummy = new ListNode<T>(-1);
    ListNode<T> *curr = dummy;

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

    ListNode<T> *res = dummy->next;
    delete dummy;
    return res;
}

template<class T>
ListNode<T> *SortList(ListNode<T> *head)
{
    if (head == nullptr || head->next == nullptr) return head;
    ListNode<T> *fast, *slow, *prev;
    fast = slow = prev = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    return merge(SortList(head), SortList(slow));
}


#endif /* LIST_NODE_H_ */
