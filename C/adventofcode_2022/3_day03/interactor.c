#include <stdio.h>
#include <stdlib.h>

#include "interactor.h"
#include "rucksack.h"
#include "item.h"

size_t sum_of_items(FILE *stream)
{
    size_t sum_of_items = 0;
    size_t sum_of_badges = 0;
    size_t len = 0;
    ssize_t nread;
    char *line = NULL;
    size_t rucksack_count = 0;
    rucksack *rucksack_list[3];
    while ((nread = getline(&line, &len, stream)) != -1)
    {
        rucksack *current_rucksack = copy_rucksack(line, nread);
        item current_repetitive_item = find_repetitive_items(current_rucksack);
        sum_of_items += current_repetitive_item_value(current_repetitive_item);
        destroy_rucksack(current_rucksack);
        ///////PART.2///////
        rucksack_list[rucksack_count] = copy_rucksack(line, nread);
        rucksack_count++;
        if(rucksack_count == 3)
        {
            item badge = find_badge(rucksack_list);
            sum_of_badges += current_repetitive_item_value(badge);
            for(size_t i = 0; i < 3; i++)
                free(rucksack_list[i]);
            rucksack_count = 0;
        }
    }
    printf("%ld\n", sum_of_badges);
    free(line);
    return sum_of_items;
}
