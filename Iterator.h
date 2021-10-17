//
// Created by chuning liu on 4/2/21.
//

#ifndef LINKED_LIST_ITERATOR_H
#define LINKED_LIST_ITERATOR_H
#include "node.h"
//#include "linkedlist.h"
template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag,T>{
public:
    Iterator();
//    Iterator(node<T> Node);
    Iterator(const Iterator& another);
    //nefore
    Iterator(node<T>* Node);
    Iterator& operator++();
    //after
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    T& operator*();
    T& operator*()const;

    Iterator<T> operator +=( const int number);
    Iterator<T> operator -=( const int number);


    Iterator<T>& operator =(Iterator<T>& RHS);
    Iterator<T>& operator =( const Iterator<T>& RHS);
    //current  =  this.current  = RHS.current
    //return this;

    template<class U>
    friend Iterator<U>& operator+( Iterator<U> LHS, const int number);
    template<class U>
    friend Iterator<U>& operator-(const Iterator<U>& LHS, const int number);

    Iterator<T> operator [](const int number);

    template<class U>
    friend bool operator ==(const Iterator<U>& LHS, const Iterator<U>&RHS);

    template<class S>
    friend bool operator !=(const Iterator<S>& LHS, const Iterator<S>& RHS);

    template<class O>
    friend ostream& operator<<(ostream& output, const Iterator<O>& iter);
private:
    node<T> *current;

};
template<typename T>
Iterator<T>::Iterator(){
  current = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const Iterator& another){
    this->current = another.current;
}

template<typename T>
Iterator<T>::Iterator(node<T>* Node){
 current = Node;
}

//before
//prefix
template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    assert(current);
    current = current->_next;
    return *this;
}
//postfix
template<typename T>
Iterator<T> Iterator<T>::operator++(int){
    assert(current);
  Iterator<T> temp = *this;
  //==(*this)

  current = current->_next;
  return temp;
}
//prefix
template<typename T>
Iterator<T>& Iterator<T>::operator--(){
    assert(current);
    current = current->_prev;
    return *this;
}
//postfix
template<typename T>
Iterator<T> Iterator<T>::operator--(int){
    assert(current);
    Iterator<T> temp = *this;
    current = current->_prev;
    return temp;
}
template<typename T>
T& Iterator<T>::operator*(){
    assert(current);
 return current->_item;
}
template<typename T>
T& Iterator<T>::operator*()const{
    assert(current);
    return  current->_item;
}

template<class U >
bool operator ==(const Iterator<U>& LHS, const Iterator<U>&RHS){
 return LHS.current == RHS.current;
}


template<class S>
bool operator !=(const Iterator<S>& LHS, const Iterator<S>& RHS){
     return LHS.current != RHS.current;
}
template<class O>
ostream& operator<<( ostream& output, const Iterator<O>& iter){
    output<<iter.current->_item;
    return output;
}

template<typename U>
//friend Iterator<T> operator+(const Iterator<T>& LHS, const int number)
Iterator<U>& operator+( Iterator<U> LHS, const int number){
    node<U>* walker = LHS.current;
    for(int i = 0; i < number;i++){
        assert(walker);
        walker = walker->_next;
//        lhs_node_pointer = lhs_node_pointer->_next;
    }
     Iterator<U> LHS_iterator = Iterator<U>(walker);
    return LHS_iterator;
//    //Iterator<T> iterator = LHS;
//    node<U>* lhs_node_pointer = LHS.current;
//    for(int i = 0; i < number;i++){
////        LHS.current = LHS.current->_next;
//        lhs_node_pointer = lhs_node_pointer->_next;
//    }
//     Iterator<U> iterator = Iterator<U>(lhs_node_pointer);
//    return iterator;
}

template<typename U>
Iterator<U>& operator-(const Iterator<U>& LHS, const int number){
    node<U>* lhs_node_pointer = LHS.current;
    for(int i = 0; i < number;i++){
        assert(lhs_node_pointer);
//        LHS.current = LHS.current->_next;
        lhs_node_pointer = lhs_node_pointer->_prev;
    }
    Iterator<U> iterator = Iterator<U>(lhs_node_pointer);
    return iterator;
}
template<typename T>
Iterator<T>& Iterator<T>::operator=(Iterator<T>& RHS){
    this->current = RHS.current;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& RHS){
    this->current = RHS.current;
    return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator +=( const int number){
    //Iterator<T> iterator = Iterator<T>(current);
    //iterator = iterator + number;
    *this = *this+number;
    return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator -=( const int number){
//    Iterator<T> iterator = Iterator<T>(current);
//    iterator = iterator - number;
      *this = *this-number;

    return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator [](const int number){
    Iterator<T> iterator = Iterator<T>(current);
    iterator = iterator + number;
     return iterator;
}

#endif //LINKED_LIST_ITERATOR_H
