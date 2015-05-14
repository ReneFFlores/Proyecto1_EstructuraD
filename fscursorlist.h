#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H
#include "object.h"
#include "tdalist.h"
#include "dllnode.h"

class Fscursorlist : public TDAList{
  protected:
    DLLNode* head;
  public:
    Fscursorlist();
    virtual ~Fscursorlist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned); //Remove
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual void reset();
    virtual Object* first()const;
    virtual Object* last()const ;
    virtual void print()const;
    virtual bool isFull()const;
    virtual int getCapacity()const;
};

#endif
