#include <stdlib.h>

#include "elf.h"
#include "elf_list.h"

void elf_append(struct elf_list *elf_list, struct elf current_elf)
{
	elf_list->size += 1;
	elf_list->elves = realloc(elf_list->elves, elf_list->size * sizeof(struct elf));
	elf_list->elves[elf_list->size-1] = current_elf;
}

void destroy_elves(struct elf_list elf_list)
{
	for (size_t i = 0; i < elf_list.size; i++)
		destroy_elf(elf_list.elves[i]);

	free(elf_list.elves);
}

unsigned long highest_n_calories(struct elf_list elf_list, size_t n)
{    
	qsort(elf_list.elves, elf_list.size, sizeof(struct elf), compare_elf);

	unsigned long count = 0;

	for (size_t i = 0; i < n; i++)
		count += total_of_calories(elf_list.elves[i]);

	return count;
}
