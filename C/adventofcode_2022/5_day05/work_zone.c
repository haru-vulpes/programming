#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "work_zone.h"

struct stack
{
    crate *crates;
//    size_t size;
};

struct dock
{
    struct stack stacks[9];
};

struct instructions
{
    size_t amount;
    size_t origin;
    size_t dest;
};

struct work_zone
{
    struct dock dock;
    struct instructions *instructions;
};

static char *string_part_1(char *str)
{
    char *string_part_1 = NULL;
    size_t index = 1;
    size_t i = 0;
    string_part_1 = malloc(10 * sizeof(char));
    while(i < 9)
    {
        string_part_1[i] = str[index];
        index+=4;
        i++;
    }
    string_part_1[9] = '\0';

    return string_part_1;
}

static struct instructions instructions_filler(char *raw_input)
{
    struct instructions instructions;

    size_t i = 0;
    size_t j = 0;
    size_t amount = 0;
    size_t origin = 0;
    size_t dest = 0;
    char *str = NULL;

    while(raw_input[j])
    {
        while(raw_input[i+j] >= '0' && raw_input[i+j] <= '9')
        {
            str = realloc(str,(i+1) * sizeof(char));
            i++;
            j++;
        }
        str[i] = '\0';
        if(dest == 0 && origin != 0)
            dest = strtol(str, NULL, 10);
        if(origin == 0 && amount != 0)
            origin = strtol(str, NULL, 10);
        if(amount == 0)
            amount = strtol(str, NULL, 10);
        free(str);
        i = 0;
        j++;
    }

    instructions.amount = amount;
    instructions.origin = origin;
    instructions.dest = dest;

    return instructions;
}

struct work_zone *work_zone_filler(char **raw_input)
{
    ssize_t i = 0;
    size_t j = 0;
    struct work_zone *work_zone;    

    work_zone = malloc(sizeof(struct work_zone));
    while(raw_input[i])
    {
        if(i>=0 && i<=7)     
            (*work_zone).dock.stacks[i].crates = string_part_1(raw_input[i]);
        if(i>=10 && raw_input[i])     
        {   
            &work_zone->instructions = realloc(work_zone->instructions, (j+1) * (sizeof(struct instructions)));
            (*work_zone).instructions[i] = instructions_filler(raw_input[i]);
            j++;
        }
        i++;
    }

    return work_zone;
}

char *result(struct work_zone *work_zone, size_t i)
{
    char *str = NULL;
    str = strdup((*work_zone).dock.stacks[i].crates);
    return str;
}

void free_work_zone(struct work_zone *work_zone)
{
    free(work_zone->instructions);
    for(size_t i = 0; i < 9; i++)
        free(work_zone->dock.stacks[i].crates);
    free(work_zone);
}
