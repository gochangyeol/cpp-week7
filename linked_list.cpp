#include "linked_list.h"
#include<iostream>
#include<exception>

// TODO: LinkedList 클래스 구현 작성

  LinkedList::LinkedList(){
    head_=nullptr;
    size_=0;
  }
  LinkedList::~LinkedList(){
   Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next_;
            delete current;
            current = next;
    }
  }
  void LinkedList::print(){
    Node *curNode=head_;
    while(curNode!=nullptr){
      std::cout<<curNode->value_<<" ";
      curNode=curNode->next_;
    }
    std::cout<<std::endl;
  }


  void LinkedList::insert(int index, int value){
    if (index < 0){
            throw std::out_of_range("Index out of range");
    }
    if(index>=0){
    Node *newNode=new Node(value);
    Node *curNode=head_;
    if(index==0){
      newNode->next_=curNode;
      head_=newNode;
      size_++;
    }
    else{
       for (int i = 0; i < index - 1; i++) {
                if (curNode==nullptr)
                    throw std::out_of_range("Index out of range");
                curNode = curNode->next_;
            }
            if (curNode==nullptr)
                throw std::out_of_range("Index out of range");

            newNode->next_=curNode->next_;
            curNode->next_=newNode;
            size_++;
    }
    }
  }
  int LinkedList::get(int index){
    if (index<0){
            throw std::out_of_range("Index out of range");
    }
    if(index>=0){
    Node *curNode=head_;
    for(int i=0;i<index;i++){
        curNode=curNode->next_;
      }
      return curNode->value_;
    }
    return 0;
  }
  void LinkedList::remove(int index){
     if (index<0){
            throw std::out_of_range("Index out of range");
     }
        if (head_==nullptr){
            throw std::out_of_range("List is empty");
        }
    if(index>=0){
    Node *curNode=head_;
    if(index==0){
      head_=curNode->next_;
      delete curNode;
      size_--;
    }
    else{
    for(int i=0;i<index-1;i++){
      curNode=curNode->next_;
    }
    Node *tmp=curNode->next_;
    curNode->next_=tmp->next_;
    delete tmp;
    size_--;
    }
    }
  }

