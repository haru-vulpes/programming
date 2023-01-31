#include <stdio.h>
#include <stdlib.h>

int main(void){

        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        size_t size = 0;
        int *array = NULL;

        while ((nread = getline(&line, &len, stdin)) != -1){
            
            size++;
            array = realloc(array, size * sizeof(int));
            array[size-1] = strtol(line, NULL, 10);
            
        }

        for (int i = 0; i < size; i++)
                printf("%d\n", array[i]);
        
        free(line);
        free(array);

        return 0;
}
