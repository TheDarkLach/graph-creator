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
