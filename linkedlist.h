#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include "object.h"
#include "tdalist.h"

class Linkedlist : public TDAList{
  class Node{
  public:
    Object* data;
    Node* next;
    Node(Object*, Node* = NULL);
    ~Node();
  };

  Node* head;
  public:
    Linkedlist();
    virtual ~Linkedlist();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    virtual Object* first()const ;
    virtual Object* last()const ;
};

#endif