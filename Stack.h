//
// Created by chuning liu on 4/2/21.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include "node.h"
#include "linkedlist.h"
#include "Iterator.h"
template <typename T>
class Stack{
public:
    typedef Iterator<T> iterator;
    Stack();
    Stack(const Stack<T>& aStack);
    ~Stack();
    T top();
    void push(const T& item);
    void pop();
    bool empty();
    void PrintStack();
    void ClearList();
    int stack_size();
    T seek(int n);

    Stack<T> &operator=(const Stack<T>& another);
    template<class U>
            friend ostream& operator<<(ostream& output, const Stack<U>& stack);

private:
    //node<T> * _top;
    LinkedList<T> _top;
};
template <typename T>
Stack<T>::Stack(){

}
template<typename T>
T Stack<T>::seek(int n){
    assert(n<stack_size());
    return _top.At(n);

}
template<typename T>
int Stack<T>::stack_size(){
    return _top.Linkedlist_size();
}
template <typename T>
Stack<T>::Stack(const Stack<T>& aStack){
   this->_top = aStack._top;

}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& another){

    this->_top = another._top;
    return *this;
}
template <typename T>
Stack<T>::~Stack(){
   this->ClearList();
}
template <typename T>
T Stack<T>::top(){
return _top.At(0);
}
template <typename T>
void Stack<T>::push(const T& item){
   _top.Insert_Head(item);
}
template <typename T>
void Stack<T>::pop(){
 _top.DeleteNode(_top.FirstNode());
}
template <typename T>
bool Stack<T>::empty(){
   if(_top.is_empty()){
       return true;
   }
   else{
       return false;
   }
}
template <typename T>
void Stack<T>::PrintStack(){
 _top.PrintList();
}
template <typename T>
void Stack<T>::ClearList(){
    _top.ClearList();
}

template<class U>
ostream& operator<<(ostream& output, const Stack<U>& stack){
     output<<stack._top;
    return output;
}
#endif //LINKED_LIST_STACK_H
