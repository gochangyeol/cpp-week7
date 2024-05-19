#include "stack.h"
#include <iostream>
#include <exception>

// TODO: Stack 클래스 구현 작성

    void Stack::push(int data){
        insert(size_,data);
    }
    int Stack::pop(){
         if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        else{
            int sum=get(size_-1);
            remove(size_-1);
            return sum;
        }
    }
    int Stack::peek(){
        if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        else{
            return get(size_-1);
        }
    }
    Stack& Stack::operator+=(int value) {
        push(value);
        return *this;
    }

