#include "vertex.h"


vertex*
new_vertex(data x) {
    vertex* v = malloc(sizeof(vertex));
    v->x    = x;
    v->link = 0;
    v->qt_adjacents = 0;
    v->qt_parallels = 0;
    // v->adjacents[0] = 3;
    // v->parallels[0] = 3;
    v->parallel_degree = 0;

    return v;
}

int
degree(vertex* v) {
    return v->qt_adjacents + v->qt_parallels + v->link;
}

void
show_vertex(vertex* v) {
    if (v == NULL)
        return;

    printf("(%d), degree %d and %d links.\n", v->x, degree(v), v->link / 2);
}

void
show_adjacents(vertex* v) {
    int len = degree(v);
    int k = 0;

    if (!len) {
        printf("This vertex is an isolated one.\n");
        return; // Este vértice é isolado.
    }

    len = v->qt_adjacents;

    if (len) {
        printf("%d: (", v->x);

        for (size_t i = 0; i < len; i++) {
            if (v->adjacents[i] == NULL)
                continue;

            printf("%d, ", v->adjacents[i]->x);

            ++k;
            // if (k % 6 == 0) // A cada linha é impresso até 6 vértices.
            //     puts("");
        }

        if (v->link)
            printf("\b\b) and has %d loops(s).\n", v->link / 2);
        else
            printf("\b\b).\n");
    }
}

void
add_adjacent(vertex* v, vertex* w) {
    if (v == w) {
        v->link += 2;
        return;
    }

    for (size_t i = 0; i < v->qt_adjacents; i++) {
        if (v->adjacents[i] == NULL)
            continue;

        if (v->adjacents[i]->x == w->x) {
            for (size_t j = 0; j < v->qt_parallels; j++) {
                if (v->parallels[j]->x == w->x) {
                    v->parallel_degree++;
                    return;
                }
            }
            v->parallels[v->qt_parallels] = w;
            v->qt_parallels++;

            return;
        }
    }

    v->adjacents[v->qt_adjacents] = w;
    v->qt_adjacents++;
}

int
is_there_parallel(vertex* v) {
    return v->qt_parallels;
}
