#include "sort.h"


void
show(data array[], unsigned int size) {
    for (unsigned int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void
insertion(data array[], unsigned int length, int(*comparator)(data, data)) {
	for (int i = 1; i < length; i++) {
		int j = i;

		while (j > 0 && comparator(array[j-1], array[j])) {
			int aux = array[j];
			array[j] = array[j - 1];
			array[j - 1] = aux;
			j--;
		}
	}
}
