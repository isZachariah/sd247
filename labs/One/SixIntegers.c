//
// Created by Zachariah Magee on 1/27/23.
//

#include "SixIntegers.h"

#include <stdio.h>
#include <stdlib.h>

void  sixIntegers() {
    int* ptr;
    int i;

    // Allocate memory for 6 integers
    ptr = (int*) malloc(6 * sizeof(int));

    if (ptr == NULL) {
        printf("Error allocating memory.\n");
    }

    // Prompt the user to enter 6 integers
    printf("Enter 6 integers: ");
    for (i = 0; i < 6; i++) {
        scanf("%d", &ptr[i]);
    }

    // Print the integers in reverse order
    printf("Integers in reverse order: ");
    for (i = 5; i >= 0; i--) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    //Free the memory
    free(ptr);

}