#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rucksack.h"
#include "item.h"

struct rucksack
{
    item *compartment_1;
    item *compartment_2;
};
static char *rucksack_to_string(rucksack rucksack)
{
    size_t n = 0;
    for(int i = 0; rucksack.compartment_1[i]; i++)
        n += 1;
    char *part_1 = strdup(rucksack.compartment_1);
    char *part_2 = strdup(rucksack.compartment_2);
    char *all_items = malloc((2*n + 1) * sizeof(char));
    for(size_t i = 0; i < n; i++)
    {
        all_items[i] = part_1[i];
        all_items[i+n] = part_2[i];
    }
    all_items[n*2] = '\0';
    free(part_1);
    free(part_2);
    return all_items;
}
rucksack *copy_rucksack(char *line, size_t n)
{
    rucksack *current_rucksack = malloc(sizeof(rucksack));
    current_rucksack->compartment_1 = strndup(line, n/2);
    current_rucksack->compartment_2 = strndup(line + n/2, n/2);
    return current_rucksack;
}
item find_repetitive_items(rucksack *current_rucksack)
{
    for(size_t i = 0; current_rucksack->compartment_1[i]; i++) 
        for(size_t j = 0; current_rucksack->compartment_2[j]; j++)
            if(current_rucksack->compartment_1[i] == current_rucksack->compartment_2[j])
                return current_rucksack->compartment_1[i];
    return '\0';
}
item find_badge(rucksack *rucksack_list[3])
{
    item badge;
    char *bag_1 = rucksack_to_string(*rucksack_list[0]);
    char *bag_2 = rucksack_to_string(*rucksack_list[1]);
    char *bag_3 = rucksack_to_string(*rucksack_list[2]);
    for(item_t i = 0; bag_1[i]; i++) 
        for(item_t j = 0; bag_2[j]; j++)
            if(bag_1[i] == bag_2[j])
                for(item_t k = 0; bag_3[k]; k++)
                    if(bag_2[j] == bag_3[k])
                    {
                        badge = bag_3[k];
                        free(bag_1);
                        free(bag_2);
                        free(bag_3);
                        for(int i = 0; i < 3; i++)
                        {
                            free(rucksack_list[i]->compartment_1);
                            free(rucksack_list[i]->compartment_2);
                        }
                        return badge;
                    }
    return '\0';
}

void destroy_rucksack(rucksack *current_rucksack)
{
    free(current_rucksack->compartment_1);
    free(current_rucksack->compartment_2);
    free(current_rucksack);
}
