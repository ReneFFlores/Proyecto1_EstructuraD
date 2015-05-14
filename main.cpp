#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tdalist.h"
#include "linkedlist.h"
#include "fsarraylist.h"
#include "fscursorlist.h"
#include "integer.h"

using namespace std;

/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
*  - Inserción
*  - Eliminación
*  - Listado
*  - Búsqueda
*/


int menu();

int main(int argc, char *argv[]){
  // En el caso de que quisieramos utilizar otra implementación
  // SÓLO se tendría que cambiar esta línea.
  TDAList* lista = new LinkedList();
  //TDAList* lista = new Fscursorlist();//FSCursorList
  //TDAList* lista = new Fsarraylist();//FSArrayList
  Integer* intTemp;
  int val, pos;
  int tam_arreglo_fijo; // para 
  bool flag = true;
  while (flag)
  {
    //
      switch(menu())
      {
         case 1:
             cout << "Valor a Insertar: " ;
             cin >> val;
             cout << "Posicion a Insertar: ";
             cin >> pos;
             if (lista->insert(new Integer(val), pos))
                cout << "Exito en la Insercion" << endl;
             else
                cout << "Fracaso en la Insercion" << endl;
             break;
         case 2:
             /*cout << "Posicion de la que quiere Borrar: ";
             cin >> pos;
             if (lista->erase(pos))
                cout << "Exito en el Borrado" << endl;
             else
                cout << "Fracaso en el Borrado" << endl;*/
             break;
         case 3:
             lista->print();
             break;
         case 4:
             cout << "Valor del Elemento a Buscar: ";
             cin >> val;
             intTemp = new Integer(val);
             pos = lista->indexOf(intTemp);
             delete intTemp;
             cout << "El Elemento esta en la posicion = " << pos << endl;
             break;
         case 9:
             flag = false;
      }

  }
  delete lista;

  return 0;
}
int menu()
{
    cout << "1. Insertar "  << endl;
    cout << "2. Borrar "  << endl;
    cout << "3. Listar " << endl;
    cout << "4. Buscar " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}
