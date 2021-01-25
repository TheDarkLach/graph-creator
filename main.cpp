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
