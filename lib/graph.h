#ifndef __graph_h
#define __graph_h

#include <stdio.h>      // printf(), puts(), scanf()...
#include <stdlib.h>     // Due dynamic memory allocation.


#include "vertex.h"
#include "sort.h"


struct graph {
    int quantity;
    vertex* vertexs[20];
};

typedef struct graph graph;

graph* new_graph(void);
vertex* add_vertex(graph* g, vertex* v);
void degree_sequence(graph* g);
void all_degrees(graph* g);

int sum(graph* g);
void are_there_links(graph* g);
void are_there_parallel(graph* g);
void degree_of_specific_vertex(graph* g, data value);

void exclude_edge(graph* g, data value1, data value2);
void adjacency_matrix(graph* g);
void show_all(graph* g);
void show_all_adjacents(graph* g);

int is_a_possible_walk(graph* g, int *ride, int length);
int ride(graph* g, int *ride, int length);
int path(graph* g, int *path, int length);
int trail(graph* g, int *trail, int length);
int cycle(graph* g, int *cycle, int length);

#endif  // graph.h
