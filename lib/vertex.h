#ifndef __vertex_h
#define __vertex_h

#include <stdio.h>
#include <stdlib.h>

typedef int data;

struct vertex {
    data x;             // Valor.
    int link;           // Laço.
    int qt_adjacents;   // Quantidade de adjacentes.
    int qt_parallels;   // Quantidade de paralelos.
    int parallel_degree;
    struct vertex* adjacents[12];
    struct vertex* parallels[12];
};

typedef struct vertex vertex;

vertex* new_vertex(data x);
// int length(vertex* v);
int degree(vertex* v);
void show_vertex(vertex* v);
void show_adjacents(vertex* v);
void add_adjacent(vertex* v, vertex* w);
int is_there_parallel(vertex* v);

#endif  // vertex.h
