#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "work_zone.h"

struct work_zone *parse(FILE *stream)
{
    ssize_t nread;
    size_t len = 0;
    char *line = NULL;
    char **raw_input = NULL;
    size_t i = 0;

    while((nread = getline(&line, &len, stream)) != -1)
    {
        raw_input = realloc(raw_input, (i+2) * sizeof(char *));
        raw_input[i] = strdup(line);
        i++;
    }
    raw_input[i] = NULL;

    struct work_zone *work_zone = work_zone_filler(raw_input); 

    free(line);

    for(size_t i = 0; raw_input[i]; i++)
        free(raw_input[i]);
    free(raw_input);

    return work_zone;
}
