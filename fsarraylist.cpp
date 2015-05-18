#include "object.h"
#include "tdalist.h"
#include "fsarraylist.h"
#include <stddef.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Fsarraylist::Fsarraylist(int most):capacity(most){
    data = new Object*[capacity];
    if(!data){
        cout << "Memoria insuficiente";
    }
}

//Deletea en un for pq sino queda eliminado el nombre, pero lo almacenado queda
Fsarraylist::~Fsarraylist(){
    for(int i = 0; i < size; i++){
        delete data[i];
    }
    delete data;
}

//insercion
bool Fsarraylist::insert(Object* other, int pos) {
    if(pos > size || pos < 0){
        return false;
    }else if(isFull()){
        return false;
    }else if (pos == size){
        data[pos] = other;
        size++;
        return true;
    }else{
        for(int i = size; i > pos; i--){
            data[i] = data[i-1];
        }

        data[pos] = other;
        size++;
        return true;
    }
}

//posicion para elemento other
int Fsarraylist::indexOf(Object* other)const {
    for(int i = 0; i < size; i++){
        if(data[i]->equals(other)){
            return i;
            break;
        }else{
            if(!data[i]->equals(other) && i == size-1){
                return -1;//indica que no existe
            }
        }
    }
}

//elemento en la posicion i
Object* Fsarraylist::get(unsigned index)const {
    if(index < 0 || index == size || index > size){
        //throw "Posicion invalida";
    }else{
        return data[index];
    }
}

//borra elemento en index
bool Fsarraylist::erase(unsigned index) {
    
}

//del indice deseado, buscar elemeto antes de el
int Fsarraylist::prev(int index_minus_one) const {
    index_minus_one--;
    if(index_minus_one < 0 || index_minus_one == size || index_minus_one > size){
        return -1;
    }else{
        return index_minus_one;
    }
}

//del indice deseado, buscar elemento despues de el, si existe
int Fsarraylist::next(int index_plus_one) const {
    index_plus_one++;
    if(index_plus_one < 0 || index_plus_one == size || index_plus_one > size){
        return -1;
    }else{
        return index_plus_one;
    }
}

//sin elementos, capacity = capacoty, size = 0
void Fsarraylist::reset() {
    if(size != 0){
        for(int i = 0; i < size; i++){
            delete data[i];
    }
        size = 0;
    }
}

Object* Fsarraylist::first()const {
    if(size == 0){
        return NULL;
    }else{
        return data[0];
    }
}

Object* Fsarraylist::last()const {
    if(size == 0){
        return NULL;
    }else{
        return data[size-1];
    }
}

void Fsarraylist::print()const {
    if(size == 0){
        cout << "Lista vacía" << endl;
    }else{
        int pos = 0;
        while(true){
            cout << pos << ".- ";
            data[pos]->print();
            if(pos+1 == size){
                break;
            }else{
                pos++;
            }
        }
    }
}

bool Fsarraylist::isFull()const {
    if(size == capacity){
        return true;
    }else{
        return false;
    }
}

int Fsarraylist::getCapacity()const{
    return capacity;
}