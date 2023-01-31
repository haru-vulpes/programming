#include <stdlib.h>

#include "elf.h"

int compare_elf(const void *lhe, const void *rhe)
{
	const struct elf *left_elf = lhe;
	const struct elf *right_elf = rhe;

	return total_of_calories(*right_elf) - total_of_calories(*left_elf);
}

void destroy_elf(struct elf elf)
{
	free(elf.calories);
}

unsigned long total_of_calories(struct elf elf)
{
	unsigned long total_of_calories = 0;

	for (size_t i = 0; i < elf.size; i++)
		total_of_calories += elf.calories[i];

	return total_of_calories;
}

void add_calories(struct elf *current_elf, unsigned long calories)
{
	current_elf->size += 1;
	current_elf->calories = realloc(current_elf->calories, current_elf->size * sizeof(unsigned long));
	current_elf->calories[current_elf->size-1] = calories;
}
