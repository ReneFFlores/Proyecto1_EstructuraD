#ifndef FSARRAYLIST_H
#define FSARRAYLIST_H
#include "object.h"
#include "tdalist.h"

class Fsarraylist : public TDAList{
  private:
    Object** data;
    int capacity;
  public:
    Fsarraylist(int);
    virtual ~Fsarraylist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned);
    virtual Object* first()const;
    virtual Object* last()const ;
};

#endif