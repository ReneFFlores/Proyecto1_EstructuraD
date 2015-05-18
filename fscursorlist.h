#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H
#include "object.h"
#include "tdalist.h"

class Fscursorlist : public TDAList{
    struct FSRow{
        Object* data;
        int next;
        int prev;
    };
    FSRow fscursor[2000];
    int head, available;
public:
    Fscursorlist(int);
    virtual ~Fscursorlist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned);
    virtual Object* first()const;
    virtual Object* last()const ;

};

#endif