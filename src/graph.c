#include "graph.h"

int
comp(data x, data y) {
    return x > y;
}

graph*
new_graph() {
    graph* g = malloc(sizeof(graph));
    g->quantity = 0;

    return g;
}

vertex*
add_vertex(graph* g, vertex* v) {
    if (g->quantity == 20) {
        printf("Graph already have 20 vertexs.\n");
        return NULL;
    }

    for (size_t i = 0; i < g->quantity; i++) {
        if (g->vertexs[i]->x == v->x) {
            return g->vertexs[i];
        }
    }

    g->vertexs[g->quantity] = v;
    g->quantity++;

    return v;
}

void
degree_sequence(graph* g) {
    if (!g->quantity)
        return;

    data d[g->quantity];

    for (size_t i = 0; i < g->quantity; i++)
        d[i] = degree(g->vertexs[i]);

    int k = 0;
    insertion(d, g->quantity, comp);

    for (size_t i = 0; i < g->quantity; i++) {
        printf("%d, ", d[i]);

        ++k;
        if (k % 5 == 0)
            puts("");
    }

    printf("\b\b.\n");
}

void
all_degrees(graph* g) {
    if (!g->quantity)
        return;

    data d[g->quantity];

    for (size_t i = 0; i < g->quantity; i++)
        d[i] = degree(g->vertexs[i]);

    int k = 0;

    for (size_t i = 0; i < g->quantity; i++) {
        printf("%d, ", d[i]);

        ++k;
        if (k % 5 == 0)
            puts("");
    }

    printf("\b\b.\n");    
}

int
sum(graph* g) {
    if (g->quantity == 0)
        return 0;
    
    int s = 0;

    for (size_t i = 0; i < g->quantity; i++)
        s += degree(g->vertexs[i]);

    return s;
}

void
are_there_links(graph* g) {
    if (g->quantity == 0)
        return;

    int counter = 0;

    for (size_t i = 0; i < g->quantity; i++) {
        if (g->vertexs[i]->link) {
            counter++;
            printf("(%d), ", g->vertexs[i]->x);
        }
    }

    if (!counter) {
        printf("There is not loops.\n\n");
        return;
   }
    printf("\b\b has loops.\n\n");
}

void
are_there_parallel(graph* g) {
    if (g->quantity == 0)
        return;

    int counter = 0;

    for (size_t i = 0; i < g->quantity; i++) {
        if (g->vertexs[i]->qt_parallels) {
            counter++;
            printf("(%d), ", g->vertexs[i]->x);
        }
    }

    if (!counter) {
        printf("There is not parallel edges.\n\n");
        return;
    }

    printf("\b\b has parallels edges.\n\n");
}

void
degree_of_specific_vertex(graph* g, data value) {
    if (!g->quantity) {
        puts("The graph is empty.");
        return;
    }

    for (size_t i = 0; i < g->quantity; i++) {
        if (g->vertexs[i]->x == value) {
            printf("The degree of (%d) is %d.\n", value, degree(g->vertexs[i]));
            return;
        }
    }
    puts("This vertex is not on the graph.");
}

void
exclude_edge(graph* g, data value1, data value2) {
    if (!g->quantity) {
        puts("The graph is empty.\n");
        return;
    }
    
    vertex* v = NULL;
    vertex* w = NULL;

    for (size_t i = 0; i < g->quantity; i++) {
        if (g->vertexs[i]->x == value1)
            v = g->vertexs[i];

        if (g->vertexs[i]->x == value2)
            w = g->vertexs[i];
    }
    
    if (v != NULL) {
        if (w != NULL) {
            for (size_t i = 0; i < v->qt_parallels; i++) {
                if (v->parallels[i]->x == w->x) {
                    v->parallels[i] = NULL;
                }
            }

            for (size_t i = 0; i < v->qt_adjacents; i++) {
                if (v->adjacents[i]->x == w->x)
                    v->adjacents[i] = NULL; // This need to be fixed (on the print).
            }

            for (size_t i = 0; i < v->qt_parallels; i++) {
                if (w->parallels[i]->x == v->x) {
                    w->parallels[i] = NULL;
                }
            }

            for (size_t i = 0; i < v->qt_adjacents; i++) {
                if (w->adjacents[i]->x == v->x)
                    w->adjacents[i] = NULL; // This need to be fixed (on the print).
            }
        } else {
            printf("The (%d) is not on the graph.\n", value2);
            return;
        }
    } else {
        printf("The (%d) is not on the graph.\n", value1);
    }    
}

void
adjacency_matrix(graph* g) {

}

void
show_all(graph* g) {
    if (!g->quantity) {
        puts("The graph is empty.");
        return;
    }
    
    for (size_t i = 0; i < g->quantity; i++)
        show_vertex(g->vertexs[i]);
}

void
show_all_adjacents(graph* g) {
    if (!g->quantity) {
        puts("The graph is empty.");
        return;
    }
    
    for (size_t i = 0; i < g->quantity; i++)
        show_adjacents(g->vertexs[i]);
}

int
is_a_possible_walk(graph* g, int* walk, int length) {
    int occurrences = 0;
    
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < g->quantity; j++) {
            if (*(walk + i) == g->vertexs[j]->x)
                occurrences++;

            if (occurrences) {
                occurrences = 0;
                break;
            } else if (j == g->quantity - 1)
                return 0;
        }
    }

    return 1;
}

int
ride(graph* g, int* ride, int length) {
    if (!is_a_possible_walk(g, ride, length))
        return 0;

    vertex* v = add_vertex(g, new_vertex(ride[0]));

    for (size_t i = 1; i < length; i++) {
        for (size_t j = 0; j < v->qt_adjacents; j++) {
            if (ride[i] == v->adjacents[j]->x) {
                v = v->adjacents[j];
                break;
            }
        }
        if (v->x != ride[i])
            return 0;
    }
    return 1;
}

int
trail(graph* g, int* trail, int length) {
    if (!ride(g, trail, length))
        return 0;
    
    if (trail[0] == trail[length-1])
        return 1;
    
    return 0;
}