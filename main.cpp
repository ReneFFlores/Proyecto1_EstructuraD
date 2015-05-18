#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "tdalist.h"
//#include "fslinkedlist.h"
#include "fsarraylist.h"
//#include "fscursorlist.h"
#include "tdalist.h"
#include "fsarraylist.h"
#include "integer.h"

using namespace std;

int main(int argc, char *argv[]){
  srand (time(0));
  //TDAList* linked_list = new LinkedList();//FSLinkedList
  //TDAList* cursor_list = new Fscursorlist();//FSCursorList
  TDAList* array_list = new Fsarraylist(1000);//FSArrayList
  Integer* intTemp;
  const int FS_SIZE = 15;

  for(int i = 0; i < FS_SIZE; i++){
    int pos = rand() % (FS_SIZE) +1;
    array_list->insert(new Integer(i), i);
    cout << "done at" << i << endl;
  }

  array_list->print();

  //delete linked_list;
  //delete cursor_list;
  delete array_list;

  return 0;
}