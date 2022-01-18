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

// Ride or walk is a traversal on a graph. 
// When the same vertex is the origin and destiny it's a closed walk, 
// otherwise it's an open walk.
int ride(graph* g, int *ride, int length);

// Trail is an open walk in which no edge is repeated.
int trail(graph* g, int *trail, int length);

// Circuit is a closed trail.
int circuit(graph* g, int *circuit, int length);

// It is a trail in which neither vertices nor edges are repeated.
int path(graph* g, int *path, int length);

// With the exception of the start and end vertex none of the others repeat, 
// also the edges do not repeat. I,e., it's a closed path.
int cycle(graph* g, int *cycle, int length);

#endif  // graph.h
