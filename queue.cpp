#include "queue.h"
#include <iostream>
#include <exception>

// TODO: Queue 클래스 구현 작성


    void Queue::push(int data){
        LinkedList::insert(size_, data);
    }
    int Queue::pop(){
         if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        else{
        int sum=LinkedList::get(0);
        LinkedList::remove(0);
        return sum;
        }
    }
    int Queue::peek(){
         if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        else{
            return LinkedList::get(0);
        }
    } 
    Queue& Queue::operator+=(int value) {
        push(value);
        return *this;
    }
