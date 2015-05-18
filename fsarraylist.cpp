#include "object.h"
#include "tdalist.h"
#include "fsarraylist.h"
#include <stddef.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Fsarraylist::Fsarraylist(int most):capacity(most){
    data = new Object*[capacity];
    if(data){
        //cout << "Memoria disponible";
    }else{
        throw "No hay memoria";
    }
}

//Deletea en un for pq sino queda eliminado el nombre, pero lo almacenado queda
Fsarraylist::~Fsarraylist(){
    int cont = 0;
    while(cont < size){
        delete data[cont];
    }
    delete data;
}

//insercion
bool Fsarraylist::insert(Object* other, int pos) {
    if(pos > size || pos < 0){
        cout << "Indice de inserción inválido" << endl;
        return false;
    }else if(size == capacity){
        cout << "Lista llena" << endl;
        return false;
    }else if (pos == size){
        data[pos] = other;
        size++;
        return true;
    }else{
        int tmp = size;
        while(tmp > pos){
            data[tmp] = data[tmp-1];
            tmp--;
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
                cout << "Elemento no existe" << endl;
                return -1;//indica que no existe
            }
        }
    }
}

//elemento en la posicion i
Object* Fsarraylist::get(unsigned index)const {
    if(index < 0 || index == size || index > size){
        cout << "Valor no valido" << endl;;
        return NULL;
    }else{
        return (data[index]);
    }
}

//borra elemento en index
bool Fsarraylist::erase(unsigned index) {
    if(index < 0 || index == size || index > size){
        cout << "Valor no válido" << endl;
        return false;
    }else{
        delete data[index];
        size--;
        return true;
    }
}

Object* Fsarraylist::first()const {
    if(size == 0){
        cout << "Lista vacía" << endl;
        return NULL;
    }else{
        return data[0];
    }
}

Object* Fsarraylist::last()const {
    if(size == 0){
        return NULL;
        cout << "Lista vacía" << endl;
    }else{
        return data[size-1];
    }
}