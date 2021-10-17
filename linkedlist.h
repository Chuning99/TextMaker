//
// Created by chuning liu on 4/2/21.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include "node.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

template<typename ITEM_TYPE>
class LinkedList {
public:
    typedef Iterator<ITEM_TYPE> iterator;

    void PrintList();

    LinkedList();

    LinkedList(LinkedList<ITEM_TYPE> &another);

    ~LinkedList();

    void PrintList_backwards();

    iterator SearchList(ITEM_TYPE key);

    iterator Insert_Head(ITEM_TYPE insertThis);

    iterator Insert_After(iterator afterThis_iter, ITEM_TYPE insertThis);

    iterator Insert_Before(iterator beforeThis,
                           ITEM_TYPE insertThis);

    iterator Insert_End(ITEM_TYPE insertThis);

    iterator PreviousNode(iterator prevToThis);

    ITEM_TYPE DeleteNode(iterator deleteThis);

    node<ITEM_TYPE> *CopyList();

    void ClearList();

    ITEM_TYPE &At(int pos) const;

    iterator LastNode();

    iterator FirstNode();

    bool is_empty();

    int Linkedlist_size() const;

    LinkedList<ITEM_TYPE> &operator=(const LinkedList<ITEM_TYPE> &another);

    LinkedList<ITEM_TYPE> &operator+=(const ITEM_TYPE another);

    //Iterator
    iterator &operator[](int pos);

    iterator Begin() const;

    iterator End() const;

    template<class U>
    friend ostream &operator<<(ostream &output, const LinkedList<U> &another);

private:
    node<ITEM_TYPE> *head;

    node<ITEM_TYPE> *findPointer(Iterator<ITEM_TYPE> it);

};

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::Begin() const {
    iterator head_iterator = iterator(head);
    return head_iterator;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::End() const{
    iterator tail_iterator = iterator(nullptr);

    return tail_iterator;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator &LinkedList<ITEM_TYPE>::operator[](int pos) {
    iterator nullIterator = iterator(nullptr);
    if (Linkedlist_size() <= pos) {
        cout << "pos must be less than linkedlist size" << endl;
        return nullIterator;
    } else {
        node<ITEM_TYPE> *walker = head;
        for (int i = 0; i < pos; i++) {
            if (walker) walker = walker->_next;
        }
        if (walker) {
            iterator iterator_walker = iterator(walker);
            return iterator_walker;
        } else {
            return nullIterator;

        }
    }
}

template<typename ITEM_TYPE>
LinkedList<ITEM_TYPE> &LinkedList<ITEM_TYPE>::operator+=(const ITEM_TYPE another) {
    node<ITEM_TYPE> *newNode = this->LastNode();
    //cout<<"last node is "<<newNode->_item;
    Insert_After(newNode, another);
    return *this;
}

template<class U>
ostream &operator<<(ostream &output, const LinkedList<U> &another) {
    node<U> *walker = another.head;
    while (walker) {
        output << *walker;
        walker = walker->_next;
    }
    cout << "|||" << endl;
    return output;
}

template<typename ITEM_TYPE>
LinkedList<ITEM_TYPE>::LinkedList(LinkedList<ITEM_TYPE> &another) {
    this->head = NULL;
    for (int i = another.Linkedlist_size() - 1; i >= 0; i--) {
        this->Insert_Head(another.At(i));
    }
}

template<typename ITEM_TYPE>
LinkedList<ITEM_TYPE>::~LinkedList() {

    ClearList();
}

template<typename ITEM_TYPE>
LinkedList<ITEM_TYPE> &LinkedList<ITEM_TYPE>::operator=(const LinkedList<ITEM_TYPE> &another) {

    for (int i = another.Linkedlist_size() - 1; i >= 0; i--) {
        this->Insert_Head(another.At(i));
    }
    return *this;
}

template<typename ITEM_TYPE>
int LinkedList<ITEM_TYPE>::Linkedlist_size() const {
    int counter = 0;
    node<ITEM_TYPE> *walker = head;
    while (walker != NULL) {
        walker = walker->_next;
        counter++;
    }
    return counter;
}

template<typename ITEM_TYPE>
bool LinkedList<ITEM_TYPE>::is_empty() {
    return head == NULL;
}

template<typename ITEM_TYPE>
LinkedList<ITEM_TYPE>::LinkedList() {
    head = NULL;
}

template<typename ITEM_TYPE>
void LinkedList<ITEM_TYPE>::PrintList() {
    node<ITEM_TYPE> *walker = head;
    while (walker) {
        cout << *walker;
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

template<typename ITEM_TYPE>
//not done
void LinkedList<ITEM_TYPE>::PrintList_backwards() {
//    helper(head);
    node<ITEM_TYPE> *walker = head;
//cout<<"walekr is "<<*walker;
    while (walker->_next != NULL) {
        walker = walker->_next;
    }
//cout<<"walekr is "<<*walker;
    while (walker != head) {
        cout << *walker;
        walker = walker->_prev;
    }
    cout << *walker;
    cout << "|||" << endl;

}


template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::SearchList(ITEM_TYPE key) {
    node<ITEM_TYPE> *walker = head;
    while (walker) {
        if (walker->_item == key) {
            return walker;
        }
        walker = walker->_next;
    }
    return nullptr;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::Insert_End(ITEM_TYPE insertThis) {
    //cout<<"test before"<<endl;

    //node<ITEM_TYPE>* newNode = this->LastNode();
    iterator newNode = this->LastNode();

    //Iterator<ITEM_TYPE> iterator_newNode = Iterator<ITEM_TYPE>(newNode);
    //cout<<"last node is "<<newNode->_item;
    iterator nulliterator = iterator(nullptr);
    if (newNode == nulliterator) {
        Insert_Head(insertThis);
    } else {
        Insert_After(newNode, insertThis);
    }
    return iterator(head);

}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::Insert_Head(ITEM_TYPE insertThis) {
    node<ITEM_TYPE> *newHead = new node<ITEM_TYPE>(insertThis);
    newHead->_next = head;
    if (head != NULL) {
        head->_prev = newHead;
    }
    //head-> newHead
    head = newHead;
    Iterator<ITEM_TYPE> iterator(head);
    return iterator;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator
LinkedList<ITEM_TYPE>::Insert_After(iterator afterThis_iter, ITEM_TYPE insertThis) {
    iterator nullIterator = Iterator<ITEM_TYPE>(nullptr);
    if (afterThis_iter == nullIterator) {
        iterator iterator(head);
        return iterator;
    }
    node<ITEM_TYPE> *newNode = new node<ITEM_TYPE>(insertThis);
    node<ITEM_TYPE> *afterThis = findPointer(afterThis_iter);

    if (afterThis->_next) {
        newNode->_next = afterThis->_next;
        afterThis->_next->_prev = newNode;
    }
    afterThis->_next = newNode;
    newNode->_prev = afterThis;

    return iterator(head);

}


template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::Insert_Before(
        iterator beforeThis,
        ITEM_TYPE insertThis) {
    iterator nullIterator = iterator(nullptr);
    if (beforeThis == nullIterator) {
        return Insert_Head(insertThis);

    }

    node<ITEM_TYPE> *iterator_beforeThis = findPointer(beforeThis);
    iterator p_iterator = PreviousNode(beforeThis);
    //node<ITEM_TYPE>* p = PreviousNode(iterator_beforeThis);
    //Iterator<ITEM_TYPE> iterator_p = findPointer(p);
    iterator iterator_head = findPointer(head);
    if (p_iterator != nullIterator) {
        iterator_head = Insert_After(p_iterator, insertThis);
    } else iterator_head = Insert_Head(insertThis);

    return iterator_head;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::PreviousNode(iterator prevToThis) {
    node<ITEM_TYPE> *prev = findPointer(prevToThis);
    iterator prev_iterator = iterator(prev->_prev);
    return prev_iterator;
}

template<typename ITEM_TYPE>
ITEM_TYPE LinkedList<ITEM_TYPE>::DeleteNode(iterator deleteThis) {
    iterator nullIterator = iterator(nullptr);
    if (deleteThis == nullIterator) return ITEM_TYPE();
    node<ITEM_TYPE> *deleteThis_iterator = findPointer(deleteThis);
    if (!deleteThis_iterator->_prev && !deleteThis_iterator->_next) {
        head = nullptr;
    } else {
        if (!deleteThis_iterator->_prev) {
            head = head->_next;
            head->_prev = nullptr;
        } else if (!deleteThis_iterator->_next) {

            node<ITEM_TYPE> *prev = deleteThis_iterator->_prev;
            prev->_next = nullptr;
            deleteThis_iterator->_prev = nullptr;
        } else {
            node<ITEM_TYPE> *prev = deleteThis_iterator->_prev;
            prev->_next = deleteThis_iterator->_next;
            deleteThis_iterator->_next->_prev = prev;
        }
    }

    ITEM_TYPE item = deleteThis_iterator->_item;
    delete deleteThis_iterator;
    return item;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE> *LinkedList<ITEM_TYPE>::CopyList() {
    node<ITEM_TYPE> *dummy = new node<ITEM_TYPE>(ITEM_TYPE());
    node<ITEM_TYPE> *walker1 = dummy;
    node<ITEM_TYPE> *walker2 = head;
    while (walker2) {
        node<ITEM_TYPE> *newNode = new node<ITEM_TYPE>(walker1->_item);
        walker1->_next = newNode;
        walker1 = walker1->_next;
        walker2 = walker2->_next;

    }

    return dummy->_next;
}

template<typename ITEM_TYPE>
void LinkedList<ITEM_TYPE>::ClearList() {
    node<ITEM_TYPE> *temp = NULL;
    while (head) {
        temp = head;
        head = head->_next;

        temp->_prev = NULL;
        temp->_next = NULL;
        delete temp;

    }
}

template<typename ITEM_TYPE>
ITEM_TYPE &LinkedList<ITEM_TYPE>::At(int pos) const {
    node<ITEM_TYPE> *walker = head;
    if (pos < Linkedlist_size()) {
        for (int i = 0; i < pos; i++) {
            if (walker) walker = walker->_next;
        }
    }


//    cout  << "Pos: " << pos << " item: " << walker->_item << endl;
//    cout << "LinkedlistSize: in AT function" << this->Linkedlist_size() << endl;
    if (walker) return walker->_item;
    else {
        ITEM_TYPE t = ITEM_TYPE();
        return t;
    }
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::FirstNode() {
    return head;
}

template<typename ITEM_TYPE>
typename LinkedList<ITEM_TYPE>::iterator LinkedList<ITEM_TYPE>::LastNode() {

    node<ITEM_TYPE> *walker = head;
//    cout << "head: " << *head << endl;
    while (walker && walker->_next) {
        //cout << "walker: " << *walker << endl;
        walker = walker->_next;
    }
    //cout<<"last node walker is "<<*walker<<endl;
    iterator walker_iterator = iterator(walker);
    return walker_iterator;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE> *LinkedList<ITEM_TYPE>::findPointer(Iterator<ITEM_TYPE> it) {
    iterator nullIterator = iterator(nullptr);
    if (it == nullIterator) {
        return nullptr;
    }

    node<ITEM_TYPE> *walker = head;
    while (iterator(walker) != it) {
        walker = walker->_next;
    }

    return walker;
}

#endif //LINKED_LIST_LINKEDLIST_H
