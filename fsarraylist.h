#ifndef FSARRAYLIST_H
#define FSARRAYLIST_H
#include "object.h"
#include "tdalist.h"

class Fsarraylist : public TDAList{
  private:
    int capacity;
    Object** data;
  public:
    Fsarraylist(int);
    virtual ~Fsarraylist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned);
    virtual void reset();
    virtual Object* first()const;
    virtual Object* last()const ;
    virtual int getCapacity()const;
};

#endif