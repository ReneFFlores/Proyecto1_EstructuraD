#include "object.h"
#include "tdalist.h"
// Definici�n de los m�todos que pueden ser definidos en la clase TDAList
// Constructor por Defecto
TDAList::TDAList(){
    size = 0;
}
// Destructor
TDAList::~TDAList(){
}

// M�todo Accesor del tama�o de la lista
int TDAList::getSize()const{
    return size;
}

