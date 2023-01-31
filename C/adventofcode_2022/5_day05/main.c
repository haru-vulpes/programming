#include <stdio.h>
#include <stdlib.h>

#include "parse.h"
#include "work_zone.h"

int main(void)
{
    printf("ok");
    struct work_zone *work_zone = parse(stdin);

    char *str = NULL;
    for(size_t i = 0; i < 9; i++)
    {
        str = result(work_zone, i);
        printf("%s", str);
        free(str);
    }
    free_work_zone(work_zone);
    return 0;
}
