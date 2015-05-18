#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "tdalist.h"
#include "linkedlist.h"
#include "fsarraylist.h"
//#include "fscursorlist.h"
#include "tdalist.h"
#include "fsarraylist.h"
#include "integer.h"
#include "string.h"

using namespace std;
using std::string;
using std::clock_t;

void time_calculate(string categoria, string tipo, int tam, double time_0, double time_1);

int main(int argc, char *argv[]){
  srand (time(0));
  const int FS_SIZE = 1100;
  const int ERASE = 500;
  TDAList* linked_list = new Linkedlist();//Linkedlist
  //TDAList* cursor_list = new Fscursorlist();//FSCursorList
  TDAList* array_list = new Fsarraylist(FS_SIZE);//FSArrayList
  const int pos = rand() % (FS_SIZE) +1;
  Integer* intTemp;

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//AGREGAR A ARREGLOS
  //ARRAYLIST
  clock_t time_0 = clock();
  for(int i = 0; i < FS_SIZE; i++){
    array_list->insert(new Integer(i), i);
  }
  clock_t time_1 = clock();
  time_calculate("Insert","ArrayList", FS_SIZE, time_0, time_1);

  //LINKEDLIST
  time_0 = clock();
  for (int i = 0; i < FS_SIZE; i++){
    linked_list->insert(new Integer(i), i);
  }
  time_1 = clock();
  time_calculate("Insert","LinesList", FS_SIZE, time_0, time_1);

  //CursorList
  time_0 = clock();
  for(int i = 0; i < FS_SIZE; i++){
    //cursor_list->insert(new Integer(i), i);
  }
  time_1 = clock();
  time_calculate("Insert","CursorList", FS_SIZE, time_0, time_1);  

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//ELIMINAR DE ARREGLOS
  //ARRAYLIST
  time_0 = clock();
  array_list->erase(ERASE);
  time_1 = clock();
  time_calculate("Erase at 500","ArrayList", FS_SIZE, time_0, time_1);

  //LINKEDLIST
  time_0 = clock();
  linked_list->erase(ERASE);
  time_1 = clock();
  time_calculate("Erase at 500","LinkedList", FS_SIZE, time_0, time_1);

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//FISRT DE ARREGLOS
  //ARRAYLIST
  time_0 = clock();
  array_list->first();
  time_1 = clock();
  time_calculate("First","ArrayList", FS_SIZE, time_0, time_1);

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//LAST DE ARREGLOS
  //ARRAYLIST
  time_0 = clock();
  array_list->last();
  time_1 = clock();
  time_calculate("Last","ArrayList", FS_SIZE, time_0, time_1);


  //delete linked_list;
  //delete cursor_list;
  //delete array_list;

  return 0;
}

void time_calculate(string categoria, string tipo, int tam, double time_0, double time_1){
  cout << categoria << ": " << tipo << ", con tamaño [" << tam << "], tiempo total: " << (time_1-time_0) << " milisegundos" << endl;;
}