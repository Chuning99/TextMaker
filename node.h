

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
#include <iostream>
using namespace std;

template <typename ITEM_TYPE>
struct node{

    node();
    node(ITEM_TYPE item);
    ~node();
    node(node& another){
        this->_item = another._item;
        this->_next = another._next;
        this->_prev = another._prev;
    }

    template <typename T>
    friend std::ostream& operator <<(std::ostream& outs, const node<T> &printMe);
    ITEM_TYPE _item;
    node* _next;
    node* _prev;
};

template <typename ITEM_TYPE>
node<ITEM_TYPE>::~node()
{

}
//default constructor
template <typename ITEM_TYPE>
node<ITEM_TYPE>::node()
{
    _item = ITEM_TYPE();
    _next = NULL;
    _prev = NULL;
}

//consturctor
template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE item)
{
    _item = item;
    _next = NULL;
    _prev = NULL;
}

template <typename T>
ostream& operator <<(std::ostream& outs, const node<T> &printthis)
{
    outs << "[" << printthis._item << "]-> ";
    return outs;
}
#endif //LINKED_LIST_NODE_H
