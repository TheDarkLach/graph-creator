/*
    Graph creator c++ Faizan Karim
 */

#include <iostream>
#include <cstring>

//colors
#define RESET "\033[0m"
#define RED   "\033[31m"
#define BLUE  "\033[34m"

#include "vertex.h"

using namespace std;


//functions
void PRINT(Vertex **list, int iC);
void ADDV(Vertex **list, int iC);
void REMOVEV(Vertex **list, int iC);
void ADDE(Vertex **list, int iC);
void REMOVEE(Vertex** list, int iC);
void FSP(Vertex **list, int iC);
Vertex* findVertex(Vertex** list, char in, int iC);

int main()
{
  //vertex list
  Vertex **list = new Vertex*[20];
  //variables
  int iC = 0;  //index counter
  while (true) {
    cout << endl << "You can: addv, removev, adde, removee, print, fsp(find shortest path), quit." << endl;
    char input[20];
    cin.get(input, 20);
    cin.clear();
    cin.ignore(10000,'\n');
    if (strcmp(input, "addv") == 0) 
    {
      ADDV(list, iC);
      iC++;
    }
    else if (strcmp(input, "removev") == 0) 
    {
      REMOVEV(list, iC);
      iC--;
    }
    else if (strcmp(input, "adde") == 0) 
    {
      ADDE(list, iC);
    }
    else if (strcmp(input, "removee") == 0) 
    {
      REMOVEE(list, iC);
    }
    else if (strcmp(input, "quit") == 0) 
    {
      cout << endl << "Quitting..." << endl;
      break;
    }
    else if (strcmp(input, "print") == 0) 
    {
      PRINT(list, iC);
    }
    else if (strcmp(input, "fsp") == 0) 
    {
      cout << endl << "Finding the shortest path with Dijkstra's Algorithm." << endl;//still can't spell it without looking it up, no clue how to say it
      FSP(list, iC);
    }
    else 
    {
      cout << endl << "Invalid input." << endl;
    }
  }
  return 0; //end program
}

void ADDV(Vertex **list, int iC) 
{
  //initialize new vector object
  Vertex* newPt = new Vertex();
  newPt->setIndex(iC);
  //read user input
  char in;
  cout << ">>Char of new vertex: ";
  cin >> in;
  cin.clear();
  cin.ignore(10000, '\n');
  //assign input values to object
  newPt->setName(in);
  //add vertex to list
  list[iC] = newPt;
  cout << endl << "Vertex " << newPt->getName() << " was added." << endl;
}

void REMOVEV(Vertex **list, int iC) 
{
  if (list[0] == NULL) 
  {
    //at least one vertex
    cout << endl << "YOu need a vertex first." << endl;
    return;
  }
  char in;
  cout << ">>Vertex to be removed: ";
  cin >> in;
  cin.clear();
  cin.ignore(10000, '\n');
  Vertex* v = findVertex(list, in, iC);
  if (v == NULL) 
  {
    cout << endl << "No such vector found. Try again." << endl;
    return;
  }
  int i = v->getIndex();
  v->~Vertex(); //remove data from vertex
  cout << "Removing vertex at index " << i << endl;
  //redo edge list of each vertex
  for (int r = 0; r < iC; r++) 
  {
    Vertex* curr = list[r];
    for (int ce = i; ce < iC; ce++) 
    {
      if (ce == iC-1) 
      {
        //case of final position edge
        curr->setEdge(ce, 0);
      } 
      else 
      {
        //move all edges above removed index down by 1 index
        int next = ce+1;
        curr->setEdge(ce, curr->getEdge(next));
      }
    }
    list[r] = curr;
  }
  //remove vertex from list
  list[i] = NULL;
  //move all elements that follow down by 1 index
  while (i < iC) 
  {
    if (i == iC-1) 
    {
      //last case
      list[i] = NULL;
      break;
    }
    list[i] = list[i+1];
    (list[i])->setIndex(i);
    i++;
  }
  cout << endl << "Vertex removed." << endl;
  /*
  cout << endl << "New vertex list:" << endl;
  for (int d = 0; d < iC--; d++) {
    cout << " " << list[d]->getName() << " idx=" << list[d]->getIndex() << endl;
    }*/
}
