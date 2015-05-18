/*#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H
#include "object.h"
#include "tdalist.h"

class Fscursorlist : public TDAList{
  public:
    Fscursorlist();
    virtual ~Fscursorlist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned);
    virtual Object* first()const;
    virtual Object* last()const ;
};

#endif
*/