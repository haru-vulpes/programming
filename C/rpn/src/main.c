#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"
#include "queue.h"
#include "lexer.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    while ((n = getline(&line, &len, stdin)) != -1)
    {
        line[n-1] = '\0';
		struct queue *input = queue_lexed(line);
        printf("%lf\n", rpn_eval(input));
		destroy_queue(input);
    }

    free(line);

    return 0;
}
