#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    
    if (argc == 1){
            printf("Error. Put a number sonofabitch\n");
            return 1;
    }

    char *str = argv[1];

    int arrsize = strtol(str, NULL, 10);

    int *array = malloc(arrsize * sizeof(int));
    
    for (int i = 0; i < arrsize; i++){
            array[i] = i+1;
    }

    for (int i = 0; i < arrsize; i++)
            printf("%d\n", array[i]);

    for (int i = 0; i < arrsize; i++)
            if (array[i] % 2 == 0)
                    printf("%d\n", array[i]);
    
    for (int i = 0; i < arrsize; i++)
            printf("%d\n", array[arrsize-1-i]);
    
    free(array);

    return 0;
}
