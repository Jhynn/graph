/*
 * Se você tiver make (nas distribuições linux é pre-instalado) no seu SO:
 * No terminal, para compilar e executar, digite: make
 *  
 * Para remover o arquivo executável, use: make clean
 * 
 * Matheus H. S. Miranda.
*/

// Caso não tenha o make, execute o comando:
// gcc -Ilib -o a.out src/*.c display.c && ./a.out

#include <stdio.h>
#include "graph.h"


int
main(void) {
    int option = 0, aux, tmp, limit = 20;
    data* n;

    graph*  g = new_graph();
    vertex* v = malloc(sizeof(vertex));
    vertex* w = malloc(sizeof(vertex));

    FILE* f = fopen("data/arestas.in", "r");

    while (fscanf(f, "%d %d", &aux, &tmp) != EOF) {
        if ((aux < 0 || aux > limit) || (tmp < 0 || tmp > limit))
            break;

        v = new_vertex(aux);
        w = new_vertex(tmp);

        v = add_vertex(g, v);
        w = add_vertex(g, w);

        add_adjacent(v, w);
        // Para tornar este grafo em dígrafo, basta omitir a instrução abaixo.
        add_adjacent(w, v);
    }

    do {
        printf("\t\t\tEnter your choice.\n");
        puts("1 - Add two vertex.\t\t\t2 - Show the degree of a specific vertex.");
        puts("3 - Show the degree of all vertexs.\t4 - Show the degree sequence");
        puts("5 - Are there loops.\t\t\t6 - Are there parallels edges.");
        puts("7 - The sum of the degrees.\t\t8 - Exclude an edge.");
        puts("9 - Show all vertexs.\t\t\t10 - Show the graph's adjacency list.");
        puts("11 - Ride\t12 - Trail");
        printf("\nEnter an option: ");
        scanf("%d", &option);
        puts("");

        switch (option) {
            case 0:
                break;

            case 1:
                puts("Please, enter the values: ");
                scanf("%d %d", &aux, &tmp);

                v = new_vertex(aux);
                w = new_vertex(tmp);

                v = add_vertex(g, v);
                w = add_vertex(g, w);

                add_adjacent(v, w);
                // Para tornar este grafo em dígrafo, basta omitir a instrução abaixo.
                add_adjacent(w, v);
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
                printf("The sum of all vertex degrees is %d.\n\n", sum(g));
                break;

            case 8:
                printf("Please, type the vertexes values: ");
                scanf("%d %d", &aux, &tmp);
                puts("");
                exclude_edge(g, aux, tmp);
                break;

            case 9:
                show_all(g);
                break;

            case 10:
                show_all_adjacents(g);
                break;

            case 11:
                printf("Type the length of the ride, please: ");
                scanf("%d", &aux);
                n = calloc(aux, sizeof(int));

                for (size_t i = 0; i < aux; i++) {
                    printf("Type, the %ldth element: ", i+1);
                    scanf("%d", &tmp);
                    *(n+i) = tmp;
                }

                if (ride(g, n, aux))
                    puts("\nIt's a valid ride.\n");
                else
                    puts("\nIt's not possible.\n");
                break;

            case 12:
                printf("Type the length of the trail, please: ");
                scanf("%d", &aux);
                n = calloc(aux, sizeof(int));

                for (size_t i = 0; i < aux; i++) {
                    printf("Type, the %ldth element: ", i+1);
                    scanf("%d", &tmp);
                    *(n+i) = tmp;
                }

                if (trail(g, n, aux))
                    puts("\nIt's a valid trail.\n");
                else
                    puts("\nIt's not possible.\n");
                break;

            default:
                puts("Please, type a valid option ─ 0 to exit.\n");
                break;
        }
    } while (option != 0);
    puts("Thank you.");
}
