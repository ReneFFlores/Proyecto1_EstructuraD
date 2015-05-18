#include "object.h"
#include "tdalist.h"
// Definición de los métodos que pueden ser definidos en la clase TDAList
// Constructor por Defecto
TDAList::TDAList(){
    size = 0;
}
// Destructor
TDAList::~TDAList(){
}

// Método Accesor del tamaño de la lista
int TDAList::getSize()const{
    return size;
}

