#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortword(const void *v_1, const void *v_2)
{
    const char *const *str1 = v_1;
    const char *const *str2 = v_2;

    return strlen(*str2) - strlen(*str1);
}

int main(void){

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **mystrs = NULL;
    size_t count = 0;

    while ((nread = getline(&line, &len, stdin)) != -1) {
            if (nread == 1)
                    continue;
            count++;
            mystrs = realloc(mystrs, count * sizeof(char *));
            mystrs[count-1] = strdup(line);

    }

    qsort(mystrs, count, sizeof(char *), sortword);

    for (size_t i = 0; i < count; i++)
            printf("%s", mystrs[i]);

    for (size_t i = 0; i < count; i++)
            free(mystrs[i]);

    free(mystrs);
    free(line);

    return 0;
}
