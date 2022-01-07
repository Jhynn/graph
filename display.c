/*
 * No terminal digite make (se o tiver - no linux é pre-instalado).
 * senão, execute o comando: gcc display.c && ./a.out
 * 
 * Matheus H. S. Miranda.
*/


#include <stdio.h>
#include "graph.c"

int
main(void) {
    int option = 0, aux, tmp, limit = 20, quantity = 0;
    graph*  g = new_graph();
    vertex* v = malloc(sizeof(vertex));
    vertex* w = malloc(sizeof(vertex));

    FILE* f = fopen("arestas.in", "r");

    while (fscanf(f, "%d %d", &aux, &tmp) != EOF) {
        if ((aux < 0 || aux > limit) || (tmp < 0 || tmp > limit)) {
            printf("break - %d\n", quantity);
            break;
        }
        v = new_vertex(aux);
        w = new_vertex(tmp);

        v = add_vertex(g, v);
        w = add_vertex(g, w);

        add_adjacent(v, w);
        add_adjacent(w, v);
    }

    do {
        printf("\t\t\tEnter your choice.\n");
        puts("1 - Add two vertex.\t\t\t2 - Show the degree of a specific vertex.");
        puts("3 - Show the degree of all vertexs.\t4 - Show the degree sequence");
        puts("5 - Are there loops.\t\t\t6 - Are there parallels edges.");
        puts("7 - The sum of the degrees.\t\t8 - Exclude an edge.");
        puts("9 - Show all vertexs.\t\t\t10 - Show the graph's adjacency list.");
        printf("\nEnter an option: ");
        scanf("%d", &option);
        puts("");

        switch (option) {
            case 1:
                puts("Please, enter the values: ");
                scanf("%d %d", &aux, &tmp);

                v = new_vertex(aux);
                w = new_vertex(tmp);
                add_adjacent(v, w);
                add_adjacent(w, v);
                add_vertex(g, v);
                add_vertex(g, w);
                break;

            case 2:
                printf("Please, enter the vertex: ");
                scanf("%d", &aux);
                degree_of_specific_vertex(g, aux);
                break;

            case 3:
                all_degrees(g);
                break;

            case 4:
                degree_sequence(g);
                break;

            case 5:
                are_there_links(g);
                break;

            case 6:
                are_there_parallel(g);
                break;

            case 7:
                printf("The sum of all vertex degrees is %d\n\n", sum(g));
                break;

            case 8:
                exclude_edge(g, tmp, aux);
            
            case 9:
                show_all(g);

            case 10:
                show_all_adjacents(g);

            default:
                break;
        }
    } while (option != 0);
}
