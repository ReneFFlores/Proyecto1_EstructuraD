#include "object.h"
#include "tdalist.h"
#include "dllnode.h"
#include "fscursorlist.h"
#include <stddef.h>

Fscursorlist::Fscursorlist(){
    head = NULL;
}

Fscursorlist::~Fscursorlist(){
    if (head)
        delete head;
}

bool Fscursorlist::insert(Object* data, int pos) {
    if (pos < 0 || pos > size)
        return false;//try

    DLLNode* neo = new DLLNode(data);
    //Continuar[Falta]
}

int Fscursorlist::indexOf(Object* other)const {
    DLLNode* tmp = head;
    for (int i=0; i < size; i++){
        // Compara cada uno de los elementos con el parámetro
        if (tmp->getData()->equals(other))
                return i;
        tmp = tmp->getNext();
    }
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posición válida
Object* Fscursorlist::get(unsigned index)const {
    if (index < 0 || index >= size)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < index; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}

bool Fscursorlist::erase(unsigned pos) {
    // Si es una posición Inválida
    if (pos < 0 || pos >= size)
        return false; // Indicar fracaso en la operación
    DLLNode* tmp;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmp = head->getNext();
        tmp->setPrev(NULL);
        head->setNext(NULL);
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == size - 1){ // Desea Borrar el último
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();
        tmp->setNext(NULL);
        toErase->setPrev(NULL);
        // Liberar Memoria
        delete toErase;
    }else { // Desea Borrar de enmedio
        // Recorrer hasta el nodo anterior al que se desea borrar
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();
        tmp->setNext(toErase->getNext());
        toErase->getNext()->setPrev(tmp);
        toErase->setNext(NULL);
        toErase->setPrev(NULL);
        // Liberar Memoria
        delete toErase;
    }
    size--; // Disminuir Tamaño
    return true; // Indicar Éxito
}

int Fscursorlist::prev(int pos) const {
    return pos - 1;
}

int Fscursorlist::next(int pos) const {
    return pos + 1;
}

void Fscursorlist::reset() {
    if (head)
        delete head;
    head = NULL;
    size = 0;
}

Object* Fscursorlist::first()const {
    if (head)
        return head->getData();
    return NULL;
}

Object* Fscursorlist::last()const {
    if (!head)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < size; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}

void Fscursorlist::print()const {
    DLLNode* tmp = head;
    for (int i=0; i < size; i++){
        tmp->print();
        tmp = tmp->getNext();
    }
}

bool Fscursorlist::isFull()const {
    return false;
}

int Fscursorlist::getCapacity()const{
    return -1;
}