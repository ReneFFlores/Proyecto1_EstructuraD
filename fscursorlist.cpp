#include "object.h"
#include "tdalist.h"
#include "fscursorlist.h"
#include <stddef.h>

Fscursorlist::Fscursorlist(int tam){
    size = 0;
    available = 0;
}

Fscursorlist::~Fscursorlist(){

}

bool Fscursorlist::insert(Object* other, int pos) {
    if(pos < 0 || pos > size || size == 3500){
        return false;
    }else{
        FSRow neo;
        neo.data = other;
        if(size == 0){
            fscursor[0] = neo;
            head = 0;
        }
        for(int i = 0; i < size; i++){
            if(fscursor[i].data == NULL){
                available = i;
                break;
            }                   
        }
        if(pos == 0 && size!=0){
            neo.next = head;
            fscursor[head].prev = available;
            fscursor[available] = neo;
            head = size;
        }else{
            int tmp = head;
            for(int i = 0; i < pos-1; i++){
               tmp = fscursor[tmp].next; 
            }
                
            neo.prev = tmp;
            neo.next = fscursor[tmp].next;
            fscursor[tmp].next = available;
            fscursor[available] = neo;          
        }
        size++;
        available = size;
        return true; 
    }

}

int Fscursorlist::indexOf(Object* other)const {
    int tmp = head;
    for(int i = 0; i < size; i++){
        if(fscursor[tmp].data->equals(other)){
            return tmp;
            break;
        }else{
            if(i == size-1 && !fscursor[tmp].data->equals(other)){
                return -1;
            }
        }
        tmp = fscursor[tmp].next;
    }
}

Object* Fscursorlist::get(unsigned index)const {
    int tmp = head;
    if(index < 0 || index > size || index == size){
        return NULL;
    }else{
        for(int i = 0; i < index;i++){
            tmp = fscursor[tmp].next;
        }
        return fscursor[tmp].data; 
    }
}

bool Fscursorlist::erase(unsigned pos) {
       if(pos < 0 || pos > size){
        return NULL;
       }else{
            if(pos == 0){
                Object* tmp_data = fscursor[0].data;
                fscursor[0].data = NULL;
                if(size > 1){
                    fscursor[1].prev = -1;
                    head = 1;
                }
                size--;
                return tmp_data;
            }else{
                int tmp = head;
                for(int i = 0;i < pos-1; i++){
                    tmp = fscursor[tmp].next;
                }
                    
                int tmp_b = fscursor[tmp].next;
                fscursor[tmp].next = fscursor[tmp_b].next;
                Object* data_b = fscursor[tmp_b].data;
                fscursor[tmp_b].data = NULL;
                fscursor[fscursor[tmp_b].next].prev = fscursor[tmp_b].prev;
                fscursor[tmp_b].next = -1;
                size--;
                return data_b;
            }

       }

}

Object* Fscursorlist::first()const {
    return fscursor[head].data;
}

Object* Fscursorlist::last()const {
     int tmp = head;
        for(int i = 0; i < size-1; i++){
            tmp = fscursor[tmp].next;
            if(i == size-2){
                return fscursor[tmp].data;
            }
        }
}