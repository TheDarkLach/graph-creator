#include <iostream>

#include "vertex.h"

using namespace std;

Vertex::Vertex() {
  //constructor
  name = '\0';
  int c = 0;
  while (c < 20) {
    edges[c] = 0;
    c++;
  }
}

Vertex::~Vertex() {
  //destructor
  name = '\0';
  index = 0;
  int i = 0;
  while (i < 20) {
    edges[i] = 0;
    i++;
  }
}

void Vertex::setName(char newN) {
  name = newN;
}

char Vertex::getName() {
  return name;
}

void Vertex::setIndex(int newI) {
  index = newI;
}

int Vertex::getIndex() {
  return index;
}

void Vertex::setEdge(int from, int val) {
  edges[from] = val;
}

int Vertex::getEdge(int from) {
  return edges[from];
}