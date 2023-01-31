#pragma once

#include "item.h"

typedef struct rucksack rucksack;

item find_repetitive_items(rucksack *current_rucksack);

item find_badge(rucksack *rucksack_list[3]);

rucksack *copy_rucksack(char *line, size_t n);

void destroy_rucksack(rucksack *current_rucksack);

