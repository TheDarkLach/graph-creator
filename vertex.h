#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
 public:
  Vertex();
  ~Vertex();
  void setName(char);
  char getName();
  void setIndex(int);
  int getIndex();
  void setEdge(int, int);
  int getEdge(int);
 private:
  char name;
  int index;
  int edges[20];
};
#endif